#include<stdio.h>
#include<string.h>
void authenticaton(char cnic[],char name[]){
    
    printf("Enter your CNIC-number:\n");
    scanf("%s",cnic);
    printf("Enter your name:\n");
    scanf("%s",name);
    return;
    }
void inventory( char productCode[4][4],int quantityInStock[],int pricePerProduct[]){
   printf("PRODUCT CODE \t QUANTITY IN STOCK \t PRICE PER PRODUCT\n");
   printf("-----------------------------------------------------\n");
    int i;
   for(i=0;i<4;i++){
    printf("%-12s\t\t%-8d\t\t%-8d\n",productCode[i],quantityInStock[i],pricePerProduct[i]);
    }
    printf("\n-----------------------------------------------------");
    printf("\n-----------------------------------------------------\n");

return;
}
void updateInventory(char productCode[4][4],int quantityInStock[],int pricePerProduct[]){
    char product2[4];
    int quantity2;
    printf("Enter the product code:\n");
    int i,j;
    scanf("%s",&product2);
   
        for(j=0;j<4;j++){
            if(strcmp(product2,productCode[j])==0){
                if(quantityInStock[j]>0){
                     printf("Enter quantity to deduct:\n");
                     scanf("%d",&quantity2);
                     if(quantityInStock[j]>=quantity2){
                     quantityInStock[j]-=quantity2;
                    return;
                    }
                    else{
                        printf("insuficient!\n");
                    }
                }
                else{
                printf("out of stock!\n");
               }

            }
            // else{
            //     // printf("product not found\n");
            // }
        }

    
return;
}
void addToCart(char productCode[4][4],int quantityInStock[],int pricePerProduct[],int *bill){
    char product[4];
    int quantity;
    
    printf("Enter the product code:\n");
    int i,j;
    scanf("%s",&product);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(strcmp(product,productCode[j])==0){
                if(quantityInStock[i]<=0){
                        printf("out of stock!\n");
                        return;
                }
                else{
                printf("Enter quantity to add to cart:\n");
                scanf("%d",&quantity);
                if(quantityInStock[i]>=quantity){
                quantityInStock[i]-=quantity;
                *bill=quantity*pricePerProduct[i];
                printf("Item added sucessfully!\n");
                return;
                }
                else{
                    printf("Insuficient!\n");
                }
                }
               }
            // else{
            //     printf("product not found\n");
            // }
        }

    }
    return;
}
void displayTotalBill(int *bill){
    char voucher;
    printf("We are offering a promocode of Eid2025 DO you have voucher?(y/n):\n");
    scanf(" %c",&voucher);
    if(voucher=='y'){
        (*bill)*=0.75;
    }
    // else{
    //     *bill=bill;
    // }
    printf("total bill=%d\n",*bill);
    return;
}
void invoice(char cnic[],char name[],int bill){
  printf("CNIC number:%s\nname:%s\ntotal bill:%d\n",cnic,name,bill);
  return;
}

int main(){
    char cnic[14];
    char name[30];
    char productCode[4][4]={"001","002","003","004"};
    int quantityInStock[4]={50,10,20,8};
    int pricePerProduct[4]={100,200,300,150};
    int bill=0;
    int choice=-1;
    
    while(choice!=7){
    printf("1)Customer information\n2)Display inventory\n3)Upadate inventory\n4)Add to cart item\n5)Display total bill \n6)Show invoice \n7)Exit the system\n");
scanf("%d",&choice);
    switch(choice){
        case 1:
        authenticaton(cnic,name);
         break;
         case 2:
          inventory(productCode,quantityInStock,pricePerProduct);
         break;
        case 3:
         updateInventory(productCode,quantityInStock,pricePerProduct);
        break; 
        case 4:
        addToCart(productCode,quantityInStock,pricePerProduct,&bill);
        break;
        case 5:
        displayTotalBill(&bill);
        break;
        case 6:
        invoice(cnic,name,bill);
        break;
        case 7:
        return 0;
        break;
        default:
        printf("Invalid!");
    }
    }
     
  return;  
}