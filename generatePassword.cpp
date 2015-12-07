#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Password {

    private:

        char *password;

        int min_length;
        int max_length;

        int min_LowcaseLen;
        int max_LowcaseLen;

        int min_UpcaseLen;
        int max_UpcaseLen;

        int min_NumLen;
        int max_NumLen;

        int min_SpecialCharLen;
        int max_SpecialCharLen;

        void setRandomChar(int min, int max, int len, int index);
        int randomLength (int min, int max);

    public:
        Password(
                int min_len   = 6, int max_len   = 6,
                int min_l_len = 3, int max_l_len = 3,
                int min_u_len = 1, int max_u_len = 1,
                int min_n_len = 1, int max_n_len = 1,
                int min_s_len = 1, int max_s_len = 1
                ) :
            min_length (min_len),
            max_length (max_len),
            min_LowcaseLen (min_l_len),
            max_LowcaseLen (max_l_len),
            min_UpcaseLen  (min_u_len),
            max_UpcaseLen  (max_u_len),
            min_NumLen     (min_n_len),
            max_NumLen     (max_n_len),
            min_SpecialCharLen (min_s_len),
            max_SpecialCharLen (max_s_len)
		{}

        ~Password()
        {
            delete[] password;
        }
        
        void genPassword();
        void printPassword();
        void swap (char *a, char *b);
        void shuffle(char* a, int n);
};

void Password :: swap (char *a, char *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Password :: shuffle(char* a, int n)
{
	for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&a[i], &a[j]);
    }
}

int Password :: randomLength (int min , int max)
{
    return ((int)(rand()%((max - min) + 1))+ min);
}

void Password :: printPassword()
{
    cout << "Password is = " << password << endl;
}

void Password :: setRandomChar(int min, int max, int len, int index)
{
    char c;
    for(int i = 0; i < len; i++)
    {
        c = randomLength(min, max);
        password[index] = (char)c;
        index++;
    }
} 

void Password :: genPassword()
{
    int length;
    int lowCaseLength, upCaseLength;
    int numLength, specialCharLength;

    do
    {    
		lowCaseLength = randomLength(min_LowcaseLen , max_LowcaseLen);
		upCaseLength = randomLength(min_UpcaseLen , max_UpcaseLen);
		numLength = randomLength(min_NumLen , max_NumLen);
		specialCharLength = randomLength(min_SpecialCharLen , max_SpecialCharLen);
		length = lowCaseLength + upCaseLength + numLength + specialCharLength;
	} while(length < min_length || length > max_length);

	password = new char[length + 1];
    cout << "Length of generated password = " << length << endl;
    
    setRandomChar('a', 'z', lowCaseLength, 0);
    setRandomChar('A', 'Z', upCaseLength, lowCaseLength);
    setRandomChar('0', '9', numLength, lowCaseLength + upCaseLength);
    setRandomChar('!', '*', specialCharLength, lowCaseLength + upCaseLength + numLength);
    
    shuffle(password, length);
    password[length + 1] = '\0';
}

int main()
{
    int type = 0;
    int min_length;
    int max_length;

    int min_LowcaseLen;
    int max_LowcaseLen;

    int min_UpcaseLen;
    int max_UpcaseLen;

    int min_NumLen;
    int max_NumLen;

    int min_SpecialCharLen;
    int max_SpecialCharLen;

    /* initialize random seed: */
    srand (time(NULL));

    cout << "Please enter 0 for simple, 1 for complex password " << endl;
    cin >> type;

    if(!type)
    {
        // Simple password
        //constructor will be called and set all the variables by default
        Password simple_password;
        simple_password.genPassword();
        simple_password.printPassword();
    }
    else
    {
        do
        {
            cout << "Enter following parameters for complex password: "<< endl;
            cout << "Enter minimum length of password "<< endl;
            cin >> min_length;
            cout << "Enter maximum length of password "<< endl;
            cin >> max_length;
            
            if(min_length > max_length)
            {
				cout << "Error in input parameters" << endl;
				continue;
			}
            
            cout << "Enter minimum number of lowercase characters(a-z)" << endl;
            cin >>min_LowcaseLen;
            cout << "Enter maximum number of lowercase characters(a-z)" << endl;
            cin >>max_LowcaseLen;
            
            if(min_LowcaseLen > max_LowcaseLen)
            {
				cout << "Error in input parameters" << endl;
				continue;
			}

            cout << "Enter minimum number of uppercase characters(A-Z) "<< endl;
            cin >> min_UpcaseLen;
            cout << "Enter maximum number of uppercase characters(A-Z) "<< endl;
            cin >> max_UpcaseLen;
            
            if(min_UpcaseLen > max_UpcaseLen)
            {
				cout << "Error in input parameters" << endl;
				continue;
			}
            
            cout << "Enter minimum number of numbers(0-9)"<< endl;
            cin >> min_NumLen;
            cout << "Enter maximum number of numbers(0-9)"<< endl;
            cin >> max_NumLen;
            
            if(min_NumLen > max_NumLen)
            {
				cout << "Error in input parameters" << endl;
				continue;
			}
            
            cout << "Enter minimum number of special characters (/-*)"<< endl;
            cin >> min_SpecialCharLen;
            cout << "Enter maximum number of special characters (/-*)"<< endl;
            cin >> max_SpecialCharLen;

            if(min_SpecialCharLen > max_SpecialCharLen)
                continue;
            else 
                break;
        }
        while (1);

        Password complex_password(
                min_length,
                max_length,
                min_LowcaseLen,
                max_LowcaseLen,
                min_UpcaseLen,
                max_UpcaseLen,
                min_NumLen,
                max_NumLen,
                min_SpecialCharLen,
                max_SpecialCharLen);

        complex_password.genPassword();
        complex_password.printPassword();
    }

    return 0;
}
