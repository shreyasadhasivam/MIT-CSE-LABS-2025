#include <stdio.h>
#include<stdlib.h>
struct disk
{
    char data;
};
typedef struct disk disk;
int main() {
    int TOTAL_BLOCKS=10;
    disk disks[TOTAL_BLOCKS];

    char c = 'a';
    for(int m=0;m<8;m++)
    {
        disks[m].data=(char)c;
        c++;
    }
    int bad_blocks_table[2][2];
    bad_blocks_table[0][0]=5;
    bad_blocks_table[0][1]=8;
    bad_blocks_table[1][0]=6;
    bad_blocks_table[1][1]=9;
    disks[8].data=disks[5].data;
    disks[9].data=disks[6].data;

    int num=0, diskNum=0;
    printf("Enter number of disks you wish to access:\n");
    scanf("%d",&num);
    for (int i = 0; i < num; i++) {
        printf("Enter disk number\n");
        scanf("%d",&diskNum);

        for(int j=0;j<2;j++)
        {
            if(bad_blocks_table[j][0]==diskNum)
                diskNum=bad_blocks_table[j][1];
        }
        printf("\nThe data on the disk is: %c\n",disks[diskNum].data);
    }
    return 0;
}