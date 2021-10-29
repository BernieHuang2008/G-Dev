#ifndef GSTRUCT_H
#define GSTRUCT_H

#include<stdio.h>

/*	copyright H.G.Cucumber	*/ 

int gcd(int m,int n)
{
	if(m%n==0)
		return n;
	else
		return gcd(n,m%n);
}

struct fraction
{
	int mom;
	int son;
	
	float value()
	{
		return son/(mom*1.0);
	}
	
	void print()
	{
		printf("%d/%d",son,mom);
	}
	
	//	约分		
	int rof() 
	{
		int g=gcd(mom,son);
		if(g==1)
			return 0;
		else
		{
			mom=mom/g;
			son=son/g;
			return 1;
		}
	}
	
	fraction rec()	//倒数 
	{
		fraction rt;
		rt.mom=son;rt.son=mom;
		rt.rof();
		return rt;
	}
	
	fraction turn(float a)	//小数转分数  
	{
		fraction rt;
		int i=1;
		while(a%1==0)
		{
			a*=10;
			i*=10;
		}
		rt.mom=i;	rt.son=a;
		return rt;
	}

	
	//PLUS
	fraction plus(fraction p2)
	{
		fraction sum;
		int g=gcd(p2.mom,mom);
		sum.son*=p2.son*(g/p2.mom)+son*(g/mom);
		sum.mom=g;
		sum.rof();
		return sum;
	}
	fraction plusi(int p2)
	{
		fraction sum;
		sum.son=son+p2*mom;
		sum.mom=mom;
		sum.rof();
		return sum;
	}
	
	//MINUS
	fraction minus(fraction a,fraction b)
	{
		fraction rt;
		rt.son=-1*b.son;rt.mom=b.mom;
		rt=a.plus(rt);
		rt.rof();
		return rt;
	}
	
	//乘法 MCL
	fraction mcl(fraction c2)
	{
		fraction rt;
		rt.mom=mom*c2.mom;
		rt.son=son*c2.son;
		rt.rof();
		return rt;
	} 
	fraction mcli(int c2)
	{
		fraction rt;
		rt.mom=mom;
		rt.son=son*c2;
		rt.rof();
		return rt;
	}
	
	//DIV
	fraction div(fraction a,fraction b)
	{
		fraction rt=a.mcl(b.rec());
		rt.rof();
		return rt;
	}
};










struct 


#endif 
