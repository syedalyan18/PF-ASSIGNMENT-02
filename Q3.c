#include<stdio.h>

void update(int grid[][3]){
int row;
int col;
printf("Enter coordinates of a sector:\n");
scanf("%d",&row);
scanf("%d",&col);
if(row>2 || row<0 || col>2 || col<0){
    printf("Invalid Coordinates!");
    return;
}
int choose,ask;
printf("Enter to update:\n1)Power status\n2)Overload warning\n3)Maintenance required\n");
scanf("%d",&choose);
printf("Enter the action 1 for \"ON\" 0 for \"Off\"\n");
scanf("%d",&ask);
int bitset=1<<(choose-1);
if(ask==1){
    grid[row][col] |= bitset;
     }
else{
    grid[row][col] &= ~bitset;
    
}
printf("Sector (%d,%d) Updated status=%d\n",row,col,grid[row][col]);

}

void query(int grid[][3],int *power,int *overload,int *maintenance){
    int row,col;
    printf("Enter the cordinates:");
    scanf("%d %d",&row,&col);
    if(row>2 || row<0 || col>2 || col<0){
    printf("Invalid Coordinates!");
    return;
}
    int status=grid[row][col];
   printf("Power status:%s\n",(status &(*power))?"yes":"no");
   printf("Overload warning:%s\n",(status&(*overload))?"yes":"no");
   printf("Maintenance required:%s\n",(status&(*maintenance))?"yes":"no");

}
void dignostic(int grid[][3],int *power,int *maintenance,int *overload){
int i,j,maintenances=0,overloads=0;

int status;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        status=grid[i][j];
       if(status&(*maintenance)){
            maintenances++;
        }
         if(status&(*overload)){
             overloads++;
        }
    }
   

}
printf("Total overloaded sectors:%d\n",maintenances);
printf("Total maintenance required sectors:%d\n",overloads);
}

int main(){
int power=(1<<0);
int overload=(1<<1);
int maintenance=(1<<2);
int grid[3][3]={0};
int choice=-1;

while (choice!=0){
printf("Select any operation:\n1)Update sector status\n2)Query sector status\n3)Run system diagnostic\n");
scanf("%d",&choice);
{
    switch (choice)
    {
    case 1:
        update(grid);
        break;
    case 2:
        query(grid,&power,&overload,&maintenance);
        break;
    case 3:
        dignostic(grid,&power,&overload,&maintenance);
        break;

    default:
    printf("Invalid!");
    break;
        
    }
}
}
return 0;
}