#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 10000

int main(void)
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


    // Read in the sequences
    char fir[LEN + 1];
    char sec[LEN + 1];
    scanf("%s", fir);
    scanf("%s", sec);
    
    // Make some variables and initialize our answer
    int ans = 0;
    int i, j;
    int k;
    
    // Find the lengths of the strings
    int n = strlen(fir);
    int m = strlen(sec);
    
    // *** Not very efficient right now
    // *** (Hopefully) We will improve this by the end of the semester
    // Try all starts in the first
    for (i = 0; i < n; i++) 
    {
        printf("The index of first string is %d \n", i);
        // Try all starts in the second
        for (j = 0; j < m; j++) 
        {
            printf("The index of second string is %d \n", j);
            // Find the best contiguous length
            for (k = 0; k + i < n && k + j < m; k++)
            {
                if (fir[i + k] != sec[j + k])
                {
                    break;
                    //flag =false;
                    //break;
                }
            }
            //For Debug/Explain
            printf("The number of chars that match from index %d of first string and %d of second strings are %d \n",i,j,k);
            if (k > ans)
            {
                ans = k;
            }
        }
    }
    
    // Print the longest sequence found 
    printf("%d\n", ans);
}
