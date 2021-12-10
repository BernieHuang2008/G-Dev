#ifndef GAPI_H
#define GAPI_H

#include<time.h>
#include<iostream>
using namespace std;
namespace t
{	
	time_t rawtime = time(NULL);
	struct tm localtm = *localtime(&rawtime);
	struct tm UTCtm = *gmtime(&rawtime);
	int sec()	{return localtm.tm_sec;}
	int min()	{return localtm.tm_min;}
	int hour()	{return localtm.tm_hour;}
	int year()	{return localtm.tm_year+1900;}
	int mon()	{return localtm.tm_mon+1;}
	int day()	{return localtm.tm_mday;}
	string get(){return asctime(&localtm);}
}
