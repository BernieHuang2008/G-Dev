#ifndef GSTRUCT_H
#define GSTRUCT_H

#include<stdio.h>
#include<math.h>
#include<iostream> 
using namespace std;

/*	copyright H.G.Cucumber	*/ 

/*	==Struct==				==Meaning==					==return==

 *	fraction				fraction
 
 		-float son			molecular
		-float mom			Denominator
		.value()			get value .................	(float)
		.print()			print fraction
		.rof()				reduction of fraction...... (int)
		.rec()				reciprocal (fraction)
		.set(f/i,[i])		Set fractional...... 		(fraction)
		.plus(fra/int)		plus.......................	(fraction)
		.minus(fra)			minus......................	(fraction)
		.mcl(fra/int)		multiplication.............	(fraction)
		.div(fra)			division...................	(fraction)
		
	
 *	angle					angle
	
		-float deg			degree
		-float min			minute
		-float sec			second
		.turnto(char)		turnto(d,m,s,n)
			-d	degree
			-m	minute
			-s	second
			-n	normal
		.set(f,f,f)			set(deg,min,sec)
		
	
 
	a2D						a 2D plane
			
		$point				struct
			-float x		X coordinate
			-float y		Y coordinate
		$line				struct
			.set(p,p)		set a line
			.in(point)		inline?....................	(bool)
		distance(p,p/l)		distance of p&p or p&l.....	(float)
		
	
	a3D						a 3D plane
	
		$point				struct
			-float x		X coordinate
			-float y		Y coordinate
			-float z		Z coordinate
		$line				struct
			.set(p,p)		set a line
			.in(point)		inline?....................	(bool)
		distance(p,p/l)		distance of p&p or p&l.....	(float)
		distance(po,pl)		distance of point&plane....	(float)
 */

int gcd(int m,int n)
{
	if(m%n==0)
		return n;
	else
		return gcd(n,m%n);
}

struct fraction
{
	float mom=1;
	float son;
	
	fraction set(int i)
	{
		fraction rt;
		son=i;
		rt.son=i;
		return rt;
	}
	
	fraction set(int s,int m)
	{
		fraction rt;
		son=s;mom=m;
		rt.son=s;rt.mom=m;
		return rt;
	}
	
	float value()
	{
		return son/(mom*1.0);
	}
	
	void print()
	{
		printf("%d/%d",son,mom);
	}
	
	//	Լ��		
	int rof() 
	{
		while(mom/1.0==mom && son/1.0==son && mom>=0)
		{
			mom*=-10;
			son*=-10;
		}
		int g=gcd(mom,son);
		if(g==1)
			return g;
		else
		{
			mom=mom/g;
			son=son/g;
			return g;
		}
	}
	
	fraction rec()	//���� 
	{
		fraction rt;
		rt.mom=son;rt.son=mom;
		rt.rof();
		return rt;
	}
	
	fraction set(float a)	//С��ת���� 
	{
		fraction rt;
		rt.mom=1;rt.son=a;
		rt.rof();
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
	fraction plus(int p2)
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
	
	//�˷� MCL
	fraction mcl(fraction c2)
	{
		fraction rt;
		rt.mom=mom*c2.mom;
		rt.son=son*c2.son;
		rt.rof();
		return rt;
	} 
	fraction mcl(int c2)
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
fraction operator+(fraction & f1,fraction & f2){return f1.plus(f2);}
fraction operator-(fraction & f1,fraction & f2){return f1.minus(f1,f2);}
fraction operator*(fraction & f1,fraction & f2){return f1.mcl(f2);}
fraction operator/(fraction & f1,fraction & f2){return f1.div(f1,f2);}
fraction operator+(fraction & f1,int & f2){return f1.plus(f2);}
fraction operator*(fraction & f1,int & f2){return f1.mcl(f2);}
fraction operator-(fraction & f1,int & f2){fraction f;return f1.minus(f1,f.set(f2));}
fraction operator/(fraction & f1,int & f2){fraction f;return f1.div(f1,f.set(f2));}
fraction operator+(fraction & f1,float & f2){return f1.plus(f2);}
fraction operator*(fraction & f1,float & f2){return f1.mcl(f2);}
fraction operator-(fraction & f1,float & f2){fraction f;return f1.minus(f1,f.set(f2));}
fraction operator/(fraction & f1,float & f2){fraction f;return f1.div(f1,f.set(f2));}
bool operator==(fraction & f1,fraction & f2){f1.rof();f2.rof();return (f1.mom==f2.mom&&f1.son==f2.son);}
bool operator!=(fraction & f1,fraction & f2){return !(f1==f2);}




struct angle
{
	float deg=0.0;
	float min=0.0;
	float sec=0.0;
	
	void set(float a,float b,float c)  {deg=a;  min=b;  sec=c;}
	
	void turnto(char c)
	{
	    if(c=='d') 
	    {
	        deg+=min/60+sec/3600;
	        min=0;sec=0;
	    }
	    if(c=='m')
	    {
	        min+=deg*60+sec/60;
	        deg=0;sec=0;
	    }
	    if(c=='s')
	    {
	        sec+=deg*3600+min*60;
	        min=0;deg=0;
	    }
	    if(c=='n')
	    {
	        int temp;
	        turnto('s');
	        temp=floor(sec);deg=temp/3600;
	        temp=floor(sec-3600*deg);min=temp/60;
	        sec=sec-deg*3600-min*60;
	    }
	}
	
	
};






class a2D
{
	public:
		
	struct point
	{
		float x;
		float y;
	};
	
	float distance(point p1,point p2)
	{
		float x=abs(p1.x-p2.x);
		float y=abs(p1.y-p2.y);
		return sqrt(y*y+x*x);
	}
	
	struct line
	{
		point p;
		fraction xy;
		void set(point p1,point p2)
		{
			p=p1;
			xy.son=p1.x-p2.x;
			xy.mom=p1.y-p2.y;
			xy.rof();
		}
		bool in(point po)
		{
			fraction b;
			b.son=p.x-po.x;
			b.mom=p.y-po.y;
			b.rof();
			return b.value()==xy.value();
		}
	};
	
	float distance(point p,line l)
	{
		point A,B,C;
		A=p;	B=l.p;
		C=l.p;	C.x += (l.xy).son;	C.y += (l.xy).mom;
		float a,b,c,p0;
		a=distance(B,C);
		b=distance(A,C);
		c=distance(A,B);
		p0=(a+b+c)/2.0;
		float s;
		s=sqrt(p0*(p0-a)*(p0-b)*(p0-c));
		return s/(a*2.0);
	}
};





class a3D
{
	private:
	struct three{
		float x,y,z;
		void rof()
		{
			while(x/1.0==x && y/1.0==y && z/1.0==z && x>=0)
			{
				x*=-10;
				y*=-10;
				z*=-10;
			}
			int g=gcd(x,y);
			g=gcd(g,z);
			x=x/g;	y=y/g;	z=z/g;
		}
	};
	 
	public:
	
	struct point
	{
		float x,y,z;
	};
	
	float distance(point p1,point p2)
	{
		return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)+pow(p1.z-p2.z,2));
	}
	
	struct line
	{
		point p;
		three xyz;
		void set(point p1,point p2)
		{
			p=p1;
			xyz.x=p1.x-p2.x;	xyz.y=p1.y-p2.y;	xyz.z=p1.z-p2.z;	xyz.rof();
		}
		bool in(point p2)
		{
			three n;
			point p1=p;
			n.x=p1.x-p2.x;	n.y=p1.y-p2.y;	n.z=p1.z-p2.z;	n.rof();
			return n.x==xyz.x&&n.y==xyz.y&&n.z==xyz.z;
		}
	};
	
	float distance(point p,line l)
	{
		point A,B,C;
		A=p;	B=l.p;
		C=l.p;	C.x += (l.xyz).x;	C.y += (l.xyz).y;	C.z+=(l.xyz).z;
		float a,b,c,p0;
		a=distance(B,C);
		b=distance(A,C);
		c=distance(A,B);
		p0=(a+b+c)/2.0;
		float s;
		s=sqrt(p0*(p0-a)*(p0-b)*(p0-c));
		return s/(a*2.0);
	}
	
	struct plane
	{
		//z=ax+by+c
		fraction a,b,c;
		point p;
		point po2;
		point po3;
		void set(point p1,point p2,point p3)
		{
			p=p1;	po2=p2;	  po3=p3;fraction f;
			a.set(((p1.z-p2.z)*(p2.y-p3.y)-(p2.z-p3.z)*(p1.y-p2.y)),((p1.x-p2.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p2.y)));
			b.set(((p1.z-p2.z)*(p2.x-p3.x)-(p2.z-p3.z)*(p1.x-p2.x)),((p1.y-p2.y)*(p2.x-p3.x)-(p2.y-p3.y)*(p1.x-p2.x)));
			c.set((b.minus(a.minus(f.set(p1.z),a*p1.x),b*p1.y)).son,(b.minus(a.minus(f.set(p1.z),a*p1.x),b*p1.y)).mom);
			a.rof();b.rof();c.rof();
		}
		bool in(point p1)
		{
			fraction x,y,z;
			x.set(p1.x);y.set(p1.y);z.set(p1.z);
			x.rof();y.rof();z.rof();
			fraction fff=a.mcl(x).plus(b.mcl(y)).plus(c);
			fff.rof();
			return z==fff;
		}
		bool in(line l)
		{
			point C;
			C=l.p;	C.x+=(l.xyz).x;	C.y+=(l.xyz).y;	C.z+=(l.xyz).z;
			return in(l.p)&&in(C);
		}
	};

	float distance(point po,plane pl)
	{
		float rt;
		float a,b,c,d,e,f;
		a=distance(pl.p,pl.po2);b=distance(pl.p,pl.po3);c=distance(pl.po2,pl.po3);
		d=distance(pl.po3,po);	e=distance(pl.po2,po);	f=distance(pl.p,po);
		float D=b*b+c*c-d*d,E=a*a+c*c-e*e,F=a*a+b*b-f*f;
		return 0.25*sqrt(4*a*a*b*b*c*c-a*a*D*D-b*b*E*E-c*c*F*F-D*E*F);
	}
};





class lll
{
public:
#define MAXLEN 1000
    short value[MAXLEN]={0};
    int length()
    {
        for(int i=1;i<=MAXLEN;i++)
        {
            if(value[MAXLEN-i]!=0)  return MAXLEN-i+1;
        }
    }
    lll plus(lll l1,lll l2)
    {
        lll rt;
        for(int i=0;i<MAXLEN;i++)
        {
            rt.value[i]+=(l1.value[i]+l2.value[i])%10;
            if(i!=MAXLEN-1)     rt.value[i+1]=(l1.value[i]+l2.value[i])/10;
        }
        return rt;
    }
    lll minus(lll l1,lll l2)
    {//TODO
        lll rt;
        for(int i=0;i<MAXLEN;i++)
        {
            rt.value[i]+=(l1.value[i]+l2.value[i])%10;
            if(i!=MAXLEN-1)     rt.value[i+1]=(l1.value[i]+l2.value[i])/10;
        }
        return rt;
    }
};





//TODO 
#endif
