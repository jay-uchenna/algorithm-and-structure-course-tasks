#include <iostream>

int main() 
{  
    system("clear");  
    char stringToCheck[] = "Love is real but never love too much. Try no to do that again.";
    unsigned int setOccuredOnce = 0, setTemp, setOccuredMoreThaneOnce = 0;
    

    //loop to check for repetition of alphabets string stringToCheck[] 
    //by setting the respective index bit is in setOccuredOnce
    //int setOccuredMoreThaneOnce bits are set to hold those alphbeths which repeated
    for(int i = 0; stringToCheck[i] != '\0'; i++)
    {
        if(stringToCheck[i] < 91) stringToCheck[i] -= 65;
        else stringToCheck[i] -=97;
        if((stringToCheck[i] < 0)|(stringToCheck[i] > 25)) continue;
        else
        {
           setTemp = 1;
           setTemp = setTemp << stringToCheck[i];
           //check if alphabet has already occured twice
           if (setOccuredMoreThaneOnce&setTemp) continue;
           //check if alphabet has occured once
           if (setOccuredOnce&setTemp)
           {
               char temp = stringToCheck[i] + 97;
               std::cout << temp << " is duplicated\n";
               //set bit that alphabet is repeated
               setOccuredMoreThaneOnce = setOccuredMoreThaneOnce|setTemp;
               continue;
           }
           setOccuredOnce = setOccuredOnce|setTemp;
        }
    }
    return 0;
} 

