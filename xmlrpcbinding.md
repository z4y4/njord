# Source Code for XMLRPC Binding #

```
/*
 * XMLRPC Library for eXtreme Deployment
 * Copyright (c) 2009 Drew University
 */
 
 // This function will take a single javascript value and encode it into XMLRPC.
 // If the function succeeds, it will return a string with the encoded value, 
 // otherwise it will return false.
function parse_single_value(value)
{
	var valueType = typeof(value);
	var retString = "<value>";
	switch(valueType)
	{
	case "string":
		retString += "<string>" + value + "</string>";
		break;
	case "number":
		if(Math.floor(value) == value)
			retString += "<i4>" + value + "</i4>";
		else 
			retString += "<double>" + value + "</double>";
		break;
	case "boolean":
		retString += "<boolean>" + (value ? "1" : "0") + "</boolean>";
		break;
	}
	if(retString != "<value>")
		return retString + "</value>";
	
	if(value instanceof Date)
	{
		retString += "<dateTime.iso8601>" + value.getUTCFullYear().toString();
		if(value.getUTCMonth() < 10) retString += "0";
		retString += value.getUTCMonth();
		if(value.getUTCDate() < 10)	retString += "0";
		retString += value.getUTCDate() + ":";
		if(value.getUTCHours() < 10) retString += "0";
		retString += value.getUTCHours() + ":";
		if(value.getUTCMinutes() < 10) retString += "0";
		retString += value.getUTCMinutes() + ":";
		if(value.getUTCSeconds() < 10) retString += "0";
		retString += value.getUTCSeconds() + "</dateTime.iso8601>";
		return retString + "</value>";
	}
	else if(value instanceof Array)
	{
		retString += "<array><data>\n";
		for(j = 0; j < value.length; j++)
		{
			var curValue = parse_single_value(value[j]);
			if(curValue == false)
				continue;
			retString += curValue;
		}
		return retString + "</data></array></value>";
	}
	else
	{
		retString += "<struct>\n";
		for each(var propName in value)
		{
			var curValue = parse_single_value(value[propName]);
			if(curValue == false)
				continue;
			retString += "<member><name>" + propName + "</name>" + curValue + "</member>\n";
		}
		return retString + "</struct></value>";
	}
	
	return false;
}

// This function will encode an XMLRPC call and an array of parameters into XML
// and return the value as a string.
function encode_xmlrpc(methodName, arrayOfValues)
{
	var messageString = "<?xml version=\"1.0\"?>\n<methodCall>\n<methodName>" + methodName + "</methodName>\n<params>\n";
	if(arrayOfValues == null)
	{
		messageString += "</params></methodCall>";
		return messageString;
	}
	if(!(arrayOfValues instanceof Array))
	{
		messageString += parse_single_value(arrayOfValues) + "</params></methodCall>";
		return messageString;
	}
	for(i = 0; i < arrayOfValues.length; i++)
	{
		var parsedValue = parse_single_value(arrayOfValues[i]);
		if(parsedValue != false)
			messageString += "<param>" + parsedValue + "</param>\n";
	}
	messageString += "</params>\n</methodCall>";
	return messageString;
}

function decode_single_value(valueElement)
{
	var type = valueElement.child(0).name();
	var value = valueElement.child(0).toString();
	if(type == 'i4' || type == 'int' || type == 'double')
		return new Number(value);
	else if(type == 'boolean')
		return value == '1' ? true:false;
	else if(type == 'dateTime.iso8601')
	{
		var year = new Number(value.substr(0, 4));
		var month = new Number(value.substr(4, 2));
		var day = new Number(value.substr(6, 2));
		var hour = new Number(value.substr(9, 2));
		var minute = new Number(value.substr(12, 2));
		var second = new Number(value.substr(15, 2));
		var date = new Date(year, month, day, hour, minute, second);
		date.setUTCHour(hour);
		return date;
	}
	else
		return value;
}

function decode_xmlrpc(xmlContent)
{
	var params = xmlContent.params;
	var retval = new Array();
	
	for(i = 0; i < params.*.length(); i++)
	{
		var curParam = params.child(i);
		var curRetval = new Array();
		for(c = 0; c < curParam.*.length(); c++)
		{
			var curValue = curParam.child(c);
			var typeName = curValue.child(0).name();
			if(typeName == 'struct')
			{
				var members = curValue.struct.member;
				var structRet = new Object();
				for(j = 0; j < members.length(); j++)
				{
					var mName = members[j].name.toString();
					structRet[mName] = decode_single_value(members[j].value);
				}
				curRetval.push(structRet);
			}
			else if(typeName == 'array')
			{
				var values = curValue.array.data.value;
				if(values == null)
				{
					curRetval.push(new Array())
					continue;
				}
				var arrayRet = new Array();
				for(j = 0; j < values.length(); j++)
					arrayRet.push(decode_single_value(values[j]));
				curRetval.push(arrayRet);
			}
			else
				curRetval.push(decode_single_value(curValue));
		}
		retval.push(curRetval);
	}
	if(retval.length == 1)
	{
		if((retval[0] instanceof Array) && retval[0].length == 1)
			return retval[0][0];
		return retval[0];
	}
	else
		return retval;
}

function xd_rpc_call(methodName, paramArray)
{
	var xmlContent = encode_xmlrpc(methodName, paramArray);
	var httpRequest = "POST /rpc/ HTTP/1.0\r\n" +
		"User-Agent: xmlrpc-njord-curl\r\n" +
		"Content-Type: text/xml\r\n" +
		"Content-Length:" + xmlContent.length + "\r\n" +
		"\r\n" +
		xmlContent;
	
	var curlObj = new Curl();
	curlObj.SetOpt(CURLOPT_CAINFO, "c:/xDeploy/ca-bundle.crt");
	curlObj.SetOpt(CURLOPT_CUSTOMREQUEST, httpRequest);
	curlObj.SetOpt(CURLOPT_URL, "https://xd.drew.edu/rpc/");
	curlObj.SetOpt(CURLOPT_HEADER, 0);
	xmlBuffer = curlObj.Perform();
	if(typeof(xmlBuffer) == "number" || typeof(xmlBuffer) == "boolean")
		return false;
	xmlBuffer = xmlBuffer.substring(xmlBuffer.indexOf("<methodResponse>", 0), xmlBuffer.length);
	xmlContent = new XML(xmlBuffer);
	return decode_xmlrpc(xmlContent);
}
```