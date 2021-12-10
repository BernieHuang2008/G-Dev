#ifndef GAI_H
#define GAI_H

#include<iostream>
#include<math.h>
using namespace std;

/*	Copyright H.G.Cucumber	*/

/*	==Function==						==Return==	
 *	AI::strsim(string,string)			-The similarit of strings	//×Ö·û´®ÏàËÆ¶È 
 */

namespace AI{
	

float strsim(string str1,string str2)
{
	int len=str1.length();
	int same=0;
	for(int i=0;i<len;i++)
	{
		if(str2.find(str1[i])!=string::npos && abs(i-str2.find(str1[i]))<=3)	same++;
	}
	return same/(len*1.0);
}


}
#endif
