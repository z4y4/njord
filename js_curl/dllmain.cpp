// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "jsapi.h"
#include "curl\curl.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

const struct JSConstDoubleSpec curlOptConsts[] = {
	{CURLOPT_VERBOSE, "CURLOPT_VERBOSE", 0, 0},
	{CURLOPT_UPLOAD, "CURLOPT_UPLOAD", 0, 0},
	{CURLOPT_UNRESTRICTED_AUTH, "CURLOPT_UNRESTRICTED_AUTH", 0, 0},
	{CURLOPT_TRANSFERTEXT, "CURLOPT_TRANSFERTEXT", 0, 0},
	{CURLOPT_SSL_VERIFYPEER, "CURLOPT_SSL_VERIFYPEER", 0, 0},
	{CURLOPT_PUT, "CURLOPT_PUT", 0, 0},
	{CURLOPT_POST, "CURLOPT_POST", 0, 0},
	{CURLOPT_NOSIGNAL, "CURLOPT_NOSIGNAL", 0, 0},
	{CURLOPT_NOPROGRESS, "CURLOPT_NOPROGRESS", 0, 0},
	{CURLOPT_NOBODY, "CURLOPT_NOBODY", 0, 0},
	{CURLOPT_NETRC, "CURLOPT_NETRC", 0, 0},
	{CURLOPT_HTTPPROXYTUNNEL, "CURLOPT_HTTPPROXYTUNNEL", 0, 0},
	{CURLOPT_HTTPGET, "CURLOPT_HTTPGET", 0, 0},
	{CURLOPT_HEADER, "CURLOPT_HEADER", 0, 0},
	{CURLOPT_FTPLISTONLY, "CURLOPT_FTPLISTONLY", 0, 0},
	{CURLOPT_FTPAPPEND, "CURLOPT_FTPAPPEND", 0, 0},
	{CURLOPT_FTP_USE_EPSV, "CURLOPT_FTP_USE_EPSV", 0, 0},
	{CURLOPT_FTP_USE_EPRT, "CURLOPT_FTP_USE_EPRT", 0, 0},
	{CURLOPT_FRESH_CONNECT, "CURLOPT_FRESH_CONNECT", 0, 0},
	{CURLOPT_FORBID_REUSE, "CURLOPT_FORBID_REUSE", 0, 0},
	{CURLOPT_FOLLOWLOCATION, "CURLOPT_FOLLOWLOCATION", 0, 0},
	{CURLOPT_FILETIME, "CURLOPT_FILETIME", 0, 0},
	{CURLOPT_FAILONERROR, "CURLOPT_FAILONERROR", 0, 0},
	{CURLOPT_DNS_USE_GLOBAL_CACHE, "CURLOPT_DNS_USE_GLOBAL_CACHE", 0, 0},
	{CURLOPT_CRLF, "CURLOPT_CRLF", 0, 0},
	{CURLOPT_COOKIESESSION, "CURLOPT_COOKIESESSION", 0, 0},
	{CURLOPT_AUTOREFERER, "CURLOPT_AUTOREFERER", 0, 0},
	{CURLOPT_BUFFERSIZE, "CURLOPT_BUFFERSIZE", 0, 0},
	{CURLOPT_CLOSEPOLICY, "CURLOPT_CLOSEPOLICY", 0, 0},
	{CURLOPT_CONNECTTIMEOUT, "CURLOPT_CONNECTTIMEOUT", 0, 0},
	{CURLOPT_DNS_CACHE_TIMEOUT, "CURLOPT_DNS_CACHE_TIMEOUT", 0, 0},
	{CURLOPT_FTPSSLAUTH, "CURLOPT_FTPSSLAUTH", 0, 0},
	{CURLOPT_HTTP_VERSION, "CURLOPT_HTTP_VERSION", 0, 0},
	{CURLOPT_HTTPAUTH, "CURLOPT_HTTPAUTH", 0, 0},
	{CURLOPT_INFILESIZE, "CURLOPT_INFILESIZE", 0, 0},
	{CURLOPT_LOW_SPEED_LIMIT, "CURLOPT_LOW_SPEED_LIMIT", 0, 0},
	{CURLOPT_LOW_SPEED_TIME, "CURLOPT_LOW_SPEED_TIME", 0, 0},
	{CURLOPT_MAXCONNECTS, "CURLOPT_MAXCONNECTS", 0, 0},
	{CURLOPT_MAXREDIRS, "CURLOPT_MAXREDIRS", 0, 0},
	{CURLOPT_PORT, "CURLOPT_PORT", 0, 0},
	{CURLOPT_PROXYAUTH, "CURLOPT_PROXYAUTH", 0, 0},
	{CURLOPT_PROXYPORT, "CURLOPT_PROXYPORT", 0, 0},
	{CURLOPT_PROXYTYPE, "CURLOPT_PROXYTYPE", 0, 0},
	{CURLOPT_RESUME_FROM, "CURLOPT_RESUME_FROM", 0, 0},
	{CURLOPT_SSL_VERIFYHOST, "CURLOPT_SSL_VERIFYHOST", 0, 0},
	{CURLOPT_SSLVERSION, "CURLOPT_SSLVERSION", 0, 0},
	{CURLOPT_TIMECONDITION, "CURLOPT_TIMECONDITION", 0, 0},
	{CURLOPT_TIMEOUT, "CURLOPT_TIMEOUT", 0, 0},
	{CURLOPT_TIMEVALUE, "CURLOPT_TIMEVALUE", 0, 0},
	{CURLOPT_CAINFO, "CURLOPT_CAINFO", 0, 0},
	{CURLOPT_CAPATH, "CURLOPT_CAPATH", 0, 0},
	{CURLOPT_COOKIE, "CURLOPT_COOKIE", 0, 0},
	{CURLOPT_COOKIEFILE, "CURLOPT_COOKIEFILE", 0, 0},
	{CURLOPT_COOKIEJAR, "CURLOPT_COOKIEJAR", 0, 0},
	{CURLOPT_CUSTOMREQUEST, "CURLOPT_CUSTOMREQUEST", 0, 0},
	{CURLOPT_EGDSOCKET, "CURLOPT_EGDSOCKET", 0, 0},
	{CURLOPT_ENCODING, "CURLOPT_ENCODING", 0, 0},
	{CURLOPT_FTPPORT, "CURLOPT_FTPPORT", 0, 0},
	{CURLOPT_INTERFACE, "CURLOPT_INTERFACE", 0, 0},
	{CURLOPT_KRB4LEVEL, "CURLOPT_KRB4LEVEL", 0, 0},
	{CURLOPT_POSTFIELDS, "CURLOPT_POSTFIELDS", 0, 0},
	{CURLOPT_PROXY, "CURLOPT_PROXY", 0, 0},
	{CURLOPT_PROXYUSERPWD, "CURLOPT_PROXYUSERPWD", 0, 0},
	{CURLOPT_RANDOM_FILE, "CURLOPT_RANDOM_FILE", 0, 0},
	{CURLOPT_RANGE, "CURLOPT_RANGE", 0, 0},
	{CURLOPT_REFERER, "CURLOPT_REFERER", 0, 0},
	{CURLOPT_SSL_CIPHER_LIST, "CURLOPT_SSL_CIPHER_LIST", 0, 0},
	{CURLOPT_SSLCERT, "CURLOPT_SSLCERT", 0, 0},
	{CURLOPT_SSLCERTPASSWD, "CURLOPT_SSLCERTPASSWD", 0, 0},
	{CURLOPT_SSLCERTTYPE, "CURLOPT_SSLCERTTYPE", 0, 0},
	{CURLOPT_SSLENGINE, "CURLOPT_SSLENGINE", 0, 0},
	{CURLOPT_SSLENGINE_DEFAULT, "CURLOPT_SSLENGINE_DEFAULT", 0, 0},
	{CURLOPT_SSLKEY, "CURLOPT_SSLKEY", 0, 0},
	{CURLOPT_SSLKEYPASSWD, "CURLOPT_SSLKEYPASSWD", 0, 0},
	{CURLOPT_SSLKEYTYPE, "CURLOPT_SSLKEYTYPE", 0, 0},
	{CURLOPT_URL, "CURLOPT_URL", 0, 0},
	{CURLOPT_USERAGENT, "CURLOPT_USERAGENT", 0, 0},
	{CURLOPT_USERPWD, "CURLOPT_USERPWD", 0, 0},
	{0, 0, 0, 0},
};

extern struct JSFunctionSpec curlClassMethods[];

JSBool curl_init(JSContext * cx, JSObject * obj, uintN argc, jsval * argv, jsval *rval);
void curl_cleanup(JSContext * cx, JSObject * obj);

JSClass curlClass = {
    "Curl",  /* name */
    JSCLASS_HAS_PRIVATE,  /* flags */
    JS_PropertyStub, JS_PropertyStub, JS_PropertyStub, JS_PropertyStub,
    JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, curl_cleanup,
    JSCLASS_NO_OPTIONAL_MEMBERS
};
#ifdef __cplusplus
extern "C" {
#endif
BOOL __declspec(dllexport) InitExports(JSContext * cx, JSObject * global)
{
	if(curl_global_init(CURL_GLOBAL_ALL) != 0)
		return FALSE;
	JS_BeginRequest(cx);
	JS_DefineConstDoubles(cx, global, (JSConstDoubleSpec*)curlOptConsts);
	JS_InitClass(cx, global, NULL, &curlClass, curl_init, 0, NULL, curlClassMethods, NULL, NULL);
	JS_EndRequest(cx);
	return TRUE;
}

BOOL __declspec(dllexport) CleanupExports(JSContext * cx, JSObject * global)
{
	curl_global_cleanup();
	return TRUE;
}
#ifdef __cplusplus
}
#endif