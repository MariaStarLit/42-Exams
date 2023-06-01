#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
    int lw = 0;

    if (argc == 2)
	{
        while (argv[1][i])
        {
            if((argv[1][i] == '\t' || argv[1][i] == ' ') && (argv[1][i+1] >= '!' && argv[1][i+1] <= '~'))
            {
                lw = i + 1;
            }		
            i++;
	    }
         while(argv[1][lw] >= '!' && argv[1][lw] <= '~')
         {
            write(1, &argv[1][lw], 1);
            lw++;
         }      	
    }
	write(1, "\n", 1);
}
