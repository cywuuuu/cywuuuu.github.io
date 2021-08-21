#include <stdio.h>

int main()
{
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		switch(n)
		{
	case 100:printf("Continue\n");break;
	case 101:printf("Switching Protocols\n");break;
	case 200:printf("OK\n");break;
	case 201:printf("Created\n");break;
	case 202:printf("Accepted\n");break;
	case 203:printf("Non-Authoritative Information\n");	break;
	case 204:printf("No Content\n");break;
	case 205:printf("Reset Content\n");	break;
	case 206:printf("Partial Content\n");break;
	case 300:printf("Multiple Choices\n");break;
	case 301:printf("Moved Permanently\n");break;
	case 302:printf("Found\n");break;
	case 303:printf("See Other\n");break;
	case 304:printf("Not Modified\n");break;
	case 305:printf("Use Proxy\n");break;
	case 306:printf("Switch Proxy\n");	break;
	case 307:printf("Temporary Redirect\n");break;
	case 308:printf("Permanent Redirect\n");break;
	case 400:printf("Bad Request\n");break;
	case 401:printf("Unauthorized\n");break;
	case 402:printf("Payment Required\n");break;
	case 403:printf("Forbidden\n");	break;
	case 404:printf("Not Found\n");break;
	case 405:printf("Method Not Allowed\n");	break;
	case 406:printf("Not Acceptable\n");break;
	case 407:printf("Proxy Authentication Required\n");break;
	case 408:printf("Request Timeout\n");	break;
	case 409:printf("Conflict\n");break;
	case 410:printf("Gone\n");break;
	case 411:printf("Length Required\n");	break;
	case 412:printf("Precondition Failed\n");break;
	case 413:printf("Payload Too Large\n");	break;
	case 414:printf("URI Too Long\n");break;
	case 415:printf("Unsupported Media Type\n");break;
	case 416:printf("Range Not Satisfiable\n");break;
	case 417:printf("Expectation Failed\n");break;
	case 426:printf("Upgrade Required\n");break;
	case 428:printf("Precondition Required\n");break;
	case 429:printf("Too Many Requests\n");break;
	case 431:printf("Request Header Fields Too Large\n");break;
	case 451:printf("Unavailable For Legal Reasons\n");break;
	case 500:printf("Internal Server Error\n");break;
	case 501:printf("Not Implemented\n");break;
	case 502:printf("Bad Gateway\n");break;
	case 503:printf("Service Unavailable\n");break;
	case 504:printf("Gateway Timeout\n");break;
	case 505:printf("HTTP Version Not Supported\n");break;
	case 511:printf("Network Authentication Required\n");break;
			default:
				break;
		}
	}
	
    return 0;
}
