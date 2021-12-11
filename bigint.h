#include <string>
#include <sstream>
using namespace std;

class bigint {
    private: 
        string str;         
    public: 
        bigint() {
            str = " "; 
        }
        bigint(string s) {
            str = s;
        }
        bigint(long long int n) {
            str = to_string(n);
        }
        bigint(const bigint &n) {
            str = n.str;
        }
	//input and output
        friend ostream &operator << (ostream& stream, const bigint &n) {
            stream << n.str;
            return stream;
        }

        friend istream &operator >> (istream& stream, bigint &n) {
            stream >> n.str;
            return stream;
        }

	bigint operator = (const std::string& num)
	{
	bigint temp(num);
	str = temp.str;
	return *this;
	}

	bigint operator =(const bigint& num)
	{
	bigint temp(num);
	str = temp.str;
	return *this;
	}

	bigint operator =(const long long int& num)
	{
	bigint temp(num);
	str = temp.str;
	return *this;
	}

	//addition and subtracitoin
	bigint operator + (const bigint& num)const{
	string result="";
	int carry=0,value;
	int i,j;
	string a=this->str,b=num.str;
	for(i=a.length()-1,j=b.length()-1;i>=0 && j>=0;i--,j--)
	{
		value=(a[i]-'0'+b[j]-'0')+carry;
		carry=value/10;
		result = to_string(value%10)+result ;
	}
	while(i>=0)
	{
		result = a[i]+result;
		i--;
	}

	if(carry!=0)
	{
	result = to_string(carry)+result;
	}
	return result;
  	}

	bigint operator - (const bigint& num)const{
	string result="";
	string a=this->str,b=num.str;
	int i,j,value,temp=0;
	for(i=a.length()-1,j=b.length()-1;i>=0 && j>=0;i--,j--)
	{
		temp=i-1;
		if(a[i]>b[j])
		{
		value = (a[i]-'0')-(b[j]-'0');
		result = to_string(value)+result;
		}
		else if(a[i]==b[j])
		{
		value=0;
		result = to_string(value)+result;
		}
		else if(a[i]<b[j])
		{
		while(temp>=0)
		{
			if((a[temp]-'0')>0)
			{
			a[temp]='0'+((a[temp]-'0')-1);
			break;
			}
			else if((a[temp]-'0')==0)
			{
			a[temp]='0'+ 9;
			}
			temp=temp-1;
		}
		value = 10+(a[i]-'0')-(b[j]-'0');
		result = to_string(value)+result;
		}
	}
	while(i>=0)
	{
	result = a[i] + result;
	i--;
	}
	return result;
	}
};


