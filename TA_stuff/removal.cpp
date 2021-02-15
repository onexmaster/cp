
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


    char orig[101];
    scanf("%s", orig);
    
    int num;
    int i, j;
    int lenOfString;
    scanf("%d", &num);
    
    // char forbid[num];
    // for (i = 0; i < num; i++)
    // {
    //     scanf(" ");
    //     scanf("%c", &forbid[i]);
    // }
    scanf(" ");
    char buffer[250];
    scanf("%[^\n]",buffer);
    char forbid[num];
    int index=0;
    int bfrsz=strlen(buffer);

    for(int i=0;i<bfrsz;i++)
    { 
        if(!isspace(buffer[i]))
        {
            forbid[index]=buffer[i];
            index++;
        }
    }

    
    lenOfString = strlen(orig);
    for (i = 0; i < lenOfString; i++)
    {
        int okay = 1;
        
        for (j = 0; j < num; j++)
        {
            if (orig[i] == forbid[j])
            {
                okay = 0;
            }
        }
        
        if (okay == 1)   
        {
            printf("%c", orig[i]);
        }
    }
    
    printf("\n");
}
