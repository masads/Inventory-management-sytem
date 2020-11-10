#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
struct user
{
    char name[40];
    char id[20];
    char password[20];
    char address[100];
    char phone_number[20];
};
struct login
{
	char id[20];
	char password[15];	
};
struct feedback
{
    char name[20];
    char f[120];
};
struct product 
{
	char company[20];
    char name[40];
    char cateogary[40];
    int stock;
    char quantity[20];
    char code[10];
    int cost;  
};
struct cart 
{
    char customer[20];
    char company[20];
    char name[40];
    char cateogary[40];
    int stock;
    char quantity[20];
    char code[10];
    int cost;  
};
struct discount
{
	char code[8];
	
	int discount;
	char company[40];
};
struct bill
{
    char name[20];
    int quantity;
    float price;
};
void user_info();
void cart(char []);
void shop_header();
void ffeedback(char check[20]);
void company_info();
void user_or_company_info_search(char []);
void main_header();
void header_inventory();
void company(char []);
void view_allproduct(char []);
void decrase_in_product_when_in_cart(char [],int);
void decrase_in_car_when_in_product_buy(char [],int);
void view_by_category(char []);
void shop(char []);
void discount_company(char []);
void discount_user(int *discount);
void category_select(char *category);
void discount_header();
void bill();
int main(void)
{
	FILE *fp,*ft;
	struct user u;
    struct login l;
    int choice=0,signup,choice_user,choice_account,choice_o_u,flag=0,check_chose,feedback_choice;
    char owner[6]="admin",owner_pas[6]="admin",o[10],o_p[10];
    char login[20],pass[20],company_name[15],company_pass[10];
    char check_id[20],check_pass[20],no;
	main:
    system("cls");
    main_header();
    printf("1.Create account\n");
    printf("2.login for user");
    printf("\n3.login for Owner");
    printf("\n4.login for company");
    printf("\n5.Signup for company");  
    printf("\n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1://user signup
                signup:
                system("cls");
                main_header();
                fp=fopen("Customers.txt","a");
                ft=fopen("id.txt","a+");
                printf("Enter Name:");
                fflush(stdin);
                gets(u.name);
                printf("Enter ID:");
                fflush(stdin);
                gets(u.id);
                strcpy(check_id,u.id);
                printf("Enter address:");
                fflush(stdin);
                gets(u.address);
                printf("Enter Phone Number:");
                fflush(stdin);
                gets(u.phone_number);
                printf("Create New Password:");
                fflush(stdin);
                gets(u.password);
                strcpy(check_pass,u.password); 
                while(fread(&l,sizeof(l),1,ft)==1)//checking already register or not            
                {   
                    if(stricmp(l.id,check_id)==0 && stricmp(l.password,check_pass)==0)
                    {
                        fclose(fp);
                        fclose(ft);
                        checker1:
                        printf("ID and Password is already used!\n1.Signup again\n2.Go back\n");
                        scanf("%d",&check_chose);
                        switch(check_chose)
                        {
                            case 1:
                                    goto signup;
                                    break;
                            case 2:
                                    goto main;
                                    break;
                            default:
                                    printf("Please entre a correct number:");
                                    getch();
                                    scanf("%c",&no);
                                    goto checker1;
                                    break;                       
                        }
                    }
                    else if(stricmp(l.id,check_id)==0)
                    {
                        fclose(fp);
                        fclose(ft);
                        checker2:
                        printf("ID is already used!\n1.Signup again\n2.Go back\n");
                        scanf("%d",&check_chose);
                        switch(check_chose)
                        {
                            case 1:
                                    goto signup;
                                    break;
                            case 2:
                                    goto main;
                                    break;
                            default:
                                    printf("Please enter a correct number:");
                                    getch();
                                    scanf("%c",&no);
                                    goto checker2;
                                    break;                       
                        }                       
                    }
                    else if(stricmp(l.password,check_pass)==0)
                    {
                        fclose(fp);
                        fclose(ft);
                        checker3:
                        printf("Password is already used!\n1.Signup again\n2.Go back\n");
                        scanf("%d",&check_chose);
                        switch(check_chose)
                        {
                            case 1:
                                    goto signup;
                                    break;
                            case 2:
                                    goto main;
                                    break;
                            default:
                                    printf("Please entre a correct number:");
                                    getch();
                                    scanf("%c",&no);
                                    goto checker3;               
                                    break;        
                        }  
                    }
                }
		        strcpy(l.id,check_id);
				strcpy(l.password,check_pass);
				printf("Signup successful!\nPress any key to go back to main menu.");
                fwrite(&u,sizeof(u),1,fp);
                fwrite(&l,sizeof(l),1,ft);
                fclose(fp);
				fclose(ft);
				getch();
				goto main;
                break;
        case 2://user login
                system("cls");
                main_header();
                printf("Enter Login ID: ");
                fflush(stdin);
                gets(login);
                fflush(stdin);
                printf("Enter Password: ");
                fflush(stdin);
                gets(pass);  
                fp=fopen("id.txt","r");
                while(fread(&l,sizeof(l),1,fp)==1)
                {
                    if(stricmp(login,l.id)==0 && stricmp(pass,l.password)==0)
                    {
                    	user:
                    	system("cls");
                    	main_header();
                    	printf("1.Shop\n");
   						printf("2.Account");
    					printf("\n3.Cart");
                        printf("\n4.Feedback"); 
  						printf("\n5.Log out\n");
                        printf("6.Exit\n");  
   						printf("Enter your choice: ");
                    	scanf("%d",&choice_user);
                    	switch(choice_user)
                    	{
                    		case 1://shop
									shop(login);
									goto user;
									break;
							case 2://User Account
									account:
									system("cls");
                    				main_header();
									printf("1.Personal Information\n");
  									printf("2.Go back\n");
  									printf("Enter your choice: ");
									scanf("%d",&choice_account);
                    				switch(choice_account)
									{
										case 1:
												system("cls");
                    							main_header();
												printf("\n=================================\n");
   												printf("      PERSONAL INFORMATION       \n");
  												printf("=================================\n");			
   												 ft=fopen("Customers.txt","r");
   												 while(fread(&u,sizeof(u),1,ft)==1)
               									{
                   								    if(stricmp(u.id,login)==0 && stricmp(u.password,pass)==0)
                   								    {
                   								 		printf("Name:%s\nID Name:%s\nPassword:%s\nAddress:%s\nPhone Numer:%s",u.name,u.id,u.password,u.address,u.phone_number);
                   								 		printf("\npress any key to go back");
														getch();
														goto account;
												    }
                 							   	}
												 fclose(ft);
												//persnal information in process
												break;
										case 2:											
												goto user;
												break;	
									}
							case 3:  
                                    cart(login);
                                    goto user;
									break;
                            case 4://feedback
                                    feedback_check:
                                    system("cls");
                                    main_header();
                                    printf("1.Do you want to give feedback\n");
                                    printf("2.Go back");
                                    printf("\n3.Exit\n");
                                    scanf("%d",&feedback_choice);
                                    switch(feedback_choice)
                                    {
                                        case 1:
                                                ffeedback(l.id);
                                                printf("Thank you for your feeedback\n");
                                                printf("Press any key to go back");
                                                getch();
                                                goto feedback_check;
                                                break;
      
                                        case 2:
                                                goto user;
                                                break;
                                        case 3:
                                                fclose(fp); 
                                                exit(0);
                                        default:
                                                system("cls");
                                                main_header();
                                                printf("Please entre a correct number:");
                                                getch();
                                                scanf("%c",&no);
                                                goto feedback_check;        

                                    }                                       
                                    fclose(fp);
                                    break;         
							case 5://log out
									system("cls");
									main_header();
                                    fclose(fp);
                					printf("Thank you for visiting");
             					    getch();
									goto main;
									break;
                            case 6://exit
                                    exit(0);
                                    break;        		
							default://wrong choice
        							system("cls");
 									header_inventory();
                                    fclose(fp);
               						printf("Please entre a correct number:");
               						getch();
                                    scanf("%c",&no);
               						goto main;				 			
						}
                        	
                    }
                     else
                    {
                            flag=1;
                    }
                }
                if(flag==1)
                {           
                        fclose(fp);
                    	printf("Wrong name or password");
                    	getch();
                        goto main;
				}
                fclose(fp);
                break;
        case 3://owner
                system("cls");
                main_header(); 
                printf("Username:");
                fflush(stdin);
                gets(o);
                printf("Password:");
                fflush(stdin);
                gets(o_p);
                if(stricmp(o,owner)==0 && stricmp(o_p,owner_pas)==0)
                {
                owner_main:
                system("cls");
                main_header();  
                int choice_owner,choice_o_company;
                printf("1.companies\n");
                printf("2.User\n");
                printf("3.Log out\n");
                printf("4.Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&choice_owner);
                switch (choice_owner)
                {
                    case 1://companies
                            owner_company:
                            system("cls");
                            main_header();
                            printf("1.All Companies information\n");
                            printf("2.Search Company by name\n");
                            printf("3.Go back\n");
                            printf("4.Exit\n");
                            printf("Enter your choice: ");
                            scanf("%d",&choice_o_company);
                            switch(choice_o_company)
                            {
                                case 1://all companies information
                                        company_info();
                                        goto owner_company;
                                        break;
                                case 2://search company ny name
                                        user_or_company_info_search("Company");
                                        goto owner_company; 
                                        break;       
                                case 3://go back
                                        goto owner_main;
                                        break;        
                                case 4://exit
                                        exit(0);
                                        break;
                            }
                            goto main;
                            break;           
                    case 2://user
                            owner_user:
                            system("cls");
                            main_header();
                            printf("1.All Users information\n");
                            printf("2.Search User by name\n");
                            printf("3.User Feedback\n");
                            printf("4.Go back\n");
                            printf("5.Exit\n");
                            printf("Enter your choice: ");
                            scanf("%d",&choice_o_u);
                            switch(choice_o_u)
                            {
                                case 1://all users information
                                        user_info();
                                        goto owner_user;
                                        break;
                                case 2://search by name
                                        user_or_company_info_search("User");
                                        goto owner_user;
                                        break;
                                case 3://user feedback
                                        ffeedback("owner");
                                        printf("\nPress any key to go back");
                                        getch();
                                        goto owner_user;
                                        break;                                                       
                                case 4://go back
                                        goto owner_main;
                                        break;        
                                case 5://exit
                                        exit(0);
                                        break;
                                default://wrong choice
                                        printf("Please entre a correct number:");
                                        getch();
                                        scanf("%c",&no);
                                        goto owner_user;     
                                        break;        
                            }
                            goto main;
                            break;
                    case 3://go back
                            goto main;
                    case 4://exit
                            exit(0);
                            break;                
                    default://wrong choice
                            printf("Please entre a correct number:");
                            getch();
                             scanf("%c",&no);
                            goto owner_main;     
                            break;            
                }
            }
            else
            {
                printf("Wrong Username or password");
                getch();
                goto main;
            }
                break;
        case 4://login for company             
                system("cls");
                main_header();
                printf("Company ID:");
                fflush(stdin);
                gets(company_name);
                printf("Password:");
                fflush(stdin);
                gets(company_pass);
                flag=1;
                ft=fopen("company_id.txt","r");
                while(fread(&l,sizeof(l),1,ft)==1)
                {
                    if(stricmp(l.id,company_name)==0 && stricmp(l.password,company_pass)==0)
                    {                        
                            company(company_name);
                            flag=0;
                            break;   
                    }
                    else
                    {
                        flag=1;
                    }        
                }
                fclose(ft);
                if(flag==1)
                {
                    printf("Wrong name or password");
                    getch();
                }
                goto main;
				break;   
             
        case 5://signup for company
                csignup:
                system("cls");
                main_header();
                fp=fopen("company.txt","a+");
                ft=fopen("company_id.txt","a+");
                printf("Enter Name:");
                fflush(stdin);
                gets(u.name);
                printf("Enter ID:");
                fflush(stdin);
                gets(u.id);
                strcpy(check_id,u.id);
                printf("Enter address:");
                fflush(stdin);
                gets(u.address);
                printf("Enter Phone Number:");
                fflush(stdin);
                gets(u.phone_number);
                printf("Create New Password:");
                fflush(stdin);
                gets(u.password);
                strcpy(check_pass,u.password); 
                while(fread(&l,sizeof(l),1,ft)==1)//checking already register or not            
                {   
                    if(stricmp(l.id,check_id)==0 && stricmp(l.password,check_pass)==0)
                    {
                        fclose(fp);
                        fclose(ft);
                        cchecker1:
                        printf("ID and Password is already used!\n1.Signup again\n2.Go back\n");
                        scanf("%d",&check_chose);
                        switch(check_chose)
                        {
                            case 1:
                                    goto csignup;
                                    break;
                            case 2:
                                    goto main;
                                    break;
                            default:
                                    printf("Please entre a correct number:");
                                    getch();
                                    goto cchecker1;
                                    break;                       
                        }
                    }
                    else if(stricmp(l.id,check_id)==0)
                    {
                        fclose(fp);
                        fclose(ft);
                        cchecker2:
                        printf("ID is already used!\n1.Signup again\n2.Go back\n");
                        scanf("%d",&check_chose);
                        switch(check_chose)
                        {
                            case 1:
                                    goto csignup;
                                    break;
                            case 2:
                                    goto main;
                                    break;
                            default:
                                    printf("Please entre a correct number:");
                                    getch();
                                    goto cchecker2;
                                    break;                       
                        }                       
                    }
                    else if(stricmp(l.password,check_pass)==0)
                    {
                        fclose(fp);
                        fclose(ft);
                        cchecker3:
                        printf("Password is already used!\n1.Signup again\n2.Go back\n");
                        scanf("%d",&check_chose);
                        switch(check_chose)
                        {
                            case 1:
                                    goto csignup;
                                    break;
                            case 2:
                                    goto main;
                                    break;
                            default:
                                    printf("Please entre a correct number:");
                                    goto cchecker3;               
                                    break;        
                        }  
                    }
                }
		        strcpy(l.id,check_id);
				strcpy(l.password,check_pass);
				printf("Signup successful!\nPress any key to go back to main menu.");
                fwrite(&u,sizeof(u),1,fp);
                fwrite(&l,sizeof(l),1,ft);
                fclose(fp);
				fclose(ft);
				getch();
				goto main;
                break;        
        case 6://exit
                system("cls");
                printf("Thank you for visiting");
                break;
        default://wrong choice
        		system("cls");
        		main_header();
                printf("Please entre a correct number:");
                getch();
                scanf("%c",&no);
                goto main;                
    }
    
}//end of main
void user_or_company_info_search(char find[10])
{
    FILE *fp;
    system("cls");
    char to_upper_letter[20];
    strcpy(to_upper_letter,find);
    strupr(to_upper_letter);
    printf("==================================\n");
    printf("        %s  INFORMATION           \n",to_upper_letter);
    printf("==================================\n");
	struct user u;
    char name[20];
    int flag=0;
    if(stricmp(find,"User")==0)
    {
        fp=fopen("Customers.txt","r");
    }
    else if(stricmp(find,"Company")==0)
    {
        fp=fopen("company.txt","r");
    }
    printf("Enter %s name to find information: ",find);
	fflush(stdin);
    gets(name);
    system("cls");
    strcpy(to_upper_letter,name);
    strupr(to_upper_letter);
    printf("==================================\n");
    printf("        %s  INFORMATION           \n",to_upper_letter);
    printf("==================================\n");
   	while(fread(&u,sizeof(u),1,fp)==1) 
    {   
         if(stricmp(u.id,name)==0)
         {
       	printf("\n\tName:%s\n\tID Name:%s\n\tPassword:%s\n\tAddress:%s\n\tPhone Numer:%s\n\n",u.name,u.id,u.password,u.address,u.phone_number);
         flag=0;
         break;  
         }
         else
         {
             flag=1;
         }     
    }
    if(flag==1)
    {
        printf("Not Found!\n");
    }
    fclose(fp);
    printf("\nPress any key to go back\n");
	getch();
}
void main_header()
{
    printf("==================================\n");
    printf("       FAST SHOPPING MART        \n");
    printf("==================================\n");
}
void discount_header()
{
    printf("==================================\n");
    printf("         DISCOUNT COUPON          \n");
    printf("==================================\n");
}
void shop_header()
{
    printf("==================================\n");
    printf("               SHOP               \n");
    printf("==================================\n");
}
void header_inventory()
{
    printf("=================================\n");
    printf("       INVENTORY MANAGEMENT      \n");
    printf("=================================\n");

}
void company(char company_name[20])
{
    FILE *fp,*ft;
	int i,choice_company,flag=0,no,add_choice;
	char ch,*ch_category,name[20],to_upper_letter[20],check_product[20];
	struct product item;
    strcpy(to_upper_letter,company_name);
    strupr(to_upper_letter);
	companyp:
    system("cls");
    printf("=================================\n");
    printf("               %s              \n",to_upper_letter);
    printf("=================================\n");
    header_inventory();
    printf("1. Add products\n");
    printf("2. Update existing products\n");
    printf("3. Remove products\n");
    printf("4. View inventory\n");
    printf("5. Discount Coupon\n");
    printf("6. Log out\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice_company);
    switch (choice_company)
    {
    	case 1:
    			system("cls");
		        header_inventory();
    			printf("\n1.Want to add\n2.Go back\n");
    			scanf("%d",&add_choice);
    			switch(add_choice)
    			{
    				case 1:
    					fp=fopen("allproducts.txt","a+");
		    			strcpy(item.company,company_name);
						ch_category=item.cateogary;
		            	category_select(ch_category);
		                system("cls");
		                header_inventory();
		        		printf("Enter product name: ");
		        	    fflush(stdin);
		        	    gets(item.name);
		        	    printf("Enter product cost: ");
		        	    scanf("%d",&item.cost);
		        	    printf("Enter product size: ");
		        	    fflush(stdin);
		        	    gets(item.quantity);
		        	    printf("Enter stock amount: ");
		        	    scanf("%d",&item.stock);
		        	    printf("Enter product code: ");
		        	     fflush(stdin);
		        	    gets(item.code);
		        	    printf("\nProduct added successfully! \nPress any key to go back to the main menu.\n");
		        	    fwrite(&item,sizeof(item),1,fp);
		        	    fclose(fp);
		        	    getch();
		        	    goto companyp;
		        	case 2:
							goto companyp;    
				}
    			
        	    break;
        case 2:
				re_update:
	        	system("cls");
	            header_inventory();	
	            fp=fopen("allproducts.txt","r");
	            ft=fopen("temp.txt","w");
                i=1;
                printf("   Name\t\tCateogary\t\tCost\t\tsize\tStock\t  Product Code\n");
                while(fread(&item,sizeof(item),1,fp)==1)
                {
                	if(stricmp(company_name,item.company)==0)
	                {	
			            printf("%-3d%-13s%-24s%-16d%-8s%-10d%s\n", i, item.name, item.cateogary, item.cost, item.quantity, item.stock, item.code);
			            i++;
			            
					}	
				}
                rewind(fp);
                printf("Enter name of the item you want to edit: ");
            	fflush(stdin);
            	gets(name);
				 while(fread(&item,sizeof(item),1,fp)==1)
	            {	            	
	                if(stricmp(company_name,item.company)==0)
	                {
		                if(stricmp(name,item.name)!=0)
	                	{
	                    	fwrite(&item,sizeof(item),1,ft);
	                	}
	                	else
	                	{
	                 	   flag=1;
	                	}
	                }
					else
	                {
	                	fwrite(&item,sizeof(item),1,ft);
					}   
	            }
	            if(flag!=1)
	            {
	                printf("Item not found!\nDo you want to retry(Y/N): ");
	                fflush(stdin);
	                scanf("%c",&ch);
	                if(ch=='Y'||ch=='y')
	                {
	                	fclose(fp);
			            fclose(ft);
	                    goto re_update;
	                }
	                else
	                {
	                    printf("Item updating cancelled!\nPress any key to go back to main menu.");
	                }
	            }
                rewind(fp);
	            while(fread(&item,sizeof(item),1,fp)==1)
	            {	            	
					if(stricmp(company_name,item.company)==0)
	                {
			            if(flag==1)
			            {
			                printf("\t\t\t---Editing %s---\n\n",name);
			                ch_category=item.cateogary;
			            	category_select(ch_category);
                            system("cls");
                            header_inventory();
			                printf("Enter product name: ");
			                fflush(stdin);
			                gets(item.name);
			                printf("Enter product cost: ");
			                scanf("%d",&item.cost);
			                printf("Enter product size: ");
                            fflush(stdin);
                            gets(item.quantity);
			                printf("Enter stock amount: ");
			                scanf("%d",&item.stock);
			                printf("Enter product code: ");
			                fflush(stdin);
                            gets(item.code);
			                fwrite(&item,sizeof(item),1,ft);
			                printf("Item successfully updated!\nPress any key to go back to main menu");
			            }
			            fclose(fp);
			            fclose(ft);
			            remove("allproducts.txt");
			            rename("temp.txt","allproducts.txt");		
			        }
		    	}
	            goto companyp;
	            break;
		case 3:
				re_delete:
	        	system("cls");
	            header_inventory();	
	            fp=fopen("allproducts.txt","r");
	            ft=fopen("temp.txt","w");
            	i=1;
                printf("   Name\t\tCateogary\t\tCost\t\tsize\tStock\t  Product Code\n");
                while(fread(&item,sizeof(item),1,fp)==1)
                {
                	if(stricmp(company_name,item.company)==0)
	                {	
			            printf("%-3d%-13s%-24s%-16d%-8s%-10d%s\n", i, item.name, item.cateogary, item.cost, item.quantity, item.stock, item.code);
			            i++;			            
					}	
				}
				rewind(fp);
				printf("Enter name of the item you want to delete: ");
            	fflush(stdin);
            	gets(name);
				while(fread(&item,sizeof(item),1,fp)==1)
	            {	            	
	                if(stricmp(company_name,item.company)==0)
	                {
		                if(stricmp(name,item.name)!=0)
	                	{
	                    	fwrite(&item,sizeof(item),1,ft);
	                	}
	                	else
	                	{
	                 	   flag=1;
	                	}
	                }
					else
	                {
	                	fwrite(&item,sizeof(item),1,ft);
					}   
	            }	            
			    fclose(fp);
			    fclose(ft);
			    remove("allproducts.txt");
                rename("temp.txt","allproducts.txt");		
				 if(flag==1)
	            {
	                printf("Item successfully deleted!\nPress any key to go back to main menu.");
	            }
	            else if(flag!=1)
                {
                    printf("Item not found!\nDo you want to retry(Y/N): ");
                    fflush(stdin);
                    scanf("%c",&ch);
                    if(ch=='Y'||ch=='y')
                    {
                        goto re_delete;
                    }
                    else
                    {
                        printf("Item deletion cancelled!\nPress any key to go back to main menu.");
                    }
                }
	            getch();
	            goto companyp;
	            break;
		case 4:
       			system("cls");
                header_inventory();
                fp=fopen("allproducts.txt","r");
                strcpy(item.company,company_name);
                i=1;
                printf("   Name\t\tCateogary\t\tCost\t\tsize\tStock\t  Product Code\n");
                while(fread(&item,sizeof(item),1,fp)==1)
                {
                	if(stricmp(company_name,item.company)==0)
	                {
	                		
			            printf("%-3d%-13s%-24s%-16d%-8s%-10d%s\n", i, item.name, item.cateogary, item.cost, item.quantity, item.stock, item.code);
			            i++;
			            
					}	
				}
                fclose(fp);
                printf("Press any key to go back");
                getch();
                goto companyp;
                break;
        case 5:
				discount_company(company_name);     
				goto companyp;   
        case 6:
				break;        
        case 7:
        		exit(0);      
        default:
                printf("Please select a correct number from menu.");
                getch();
                scanf("%c",&no);
                goto companyp;					    
	}
	return ;
}

void shop(char check[20])
{
    FILE *fp,*ft;
    int choice_shop,no;
   	shop_main:
   	system("cls");
    shop_header();
    printf("1. All Products\n");
    printf("2. Chose category\n");
    printf("3. Go back\n");
	printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice_shop);
    switch(choice_shop)
    {
        case 1://allproducts
                view_allproduct(check);
                goto shop_main;
                break;	
        case 2://chose category
                 view_by_category(check);
                goto shop_main;
                break;
		case 3://go back
				break;
		case 4://exit
				exit(0);
		default://wrong choice
                printf("Please select a correct number from menu.");
                getch();
                scanf("%c",&no);	
				goto shop_main;					
    }    
}
void user_info()
{
	FILE *fp;
	system("cls");
    printf("==================================\n");
    printf("          USER INFORMATION        \n");
    printf("==================================\n");
	struct user u;
    int i=1;
    fp=fopen("Customers.txt","r");
   	while(fread(&u,sizeof(u),1,fp)==1)
	{      
       	printf("\t\tUser-%s\n\tName:%s\n\tID Name:%s\n\tPassword:%s\n\tAddress:%s\n\tPhone Numer:%s\n\n",u.id,u.name,u.id,u.password,u.address,u.phone_number);
     	i++;    
    }
    fclose(fp);
    printf("\nPress any key to go back\n");
	getch();
}
void company_info()
{
	FILE *fp;
    system("cls");
    printf("==================================\n");
    printf("       COMPANY INFORMATION        \n");
    printf("==================================\n");
	struct user u;
    int i=1;
    fp=fopen("company.txt","r");
   	while(fread(&u,sizeof(u),1,fp)==1)
	{        
       	printf("\t\tCompany-%d\n\tName:%s\n\tID Name:%s\n\tPassword:%s\n\tAddress:%s\n\tPhone Numer:%s\n\n",i,u.name,u.id,u.password,u.address,u.phone_number);
     	i++;    
    }
    fclose(fp);
    printf("\nPress any key to go back\n");
	getch();
}
void view_by_category(char check[20])
{
    FILE *fp,*ft,*fs,*fst;
    struct product item;
    struct cart c;
    struct discount d;
    struct bill list[100];
    int discount=0,product_count=0,no;
    float dtotal=0,dis=0;
    int re_chose,i,j=0,flag=0,quantity,price,total=0,choice,add_or_buy_product,already_in_cart;
    char name[20],*ch_category,category[20],ch;
    product:
    system("cls");
    shop_header();
    fp=fopen("allproducts.txt","r");
    ch_category=category;
    category_select(ch_category);
    system("cls");
    shop_header();
    i=1;
    j=0;	
    printf("   Name\t\tCateogary\t\tCost\t\tsize(Kg/litre)\tStock\t  Product Code\tCompany\n");
    while(fread(&item,sizeof(item),1,fp)==1)
    {
        if(stricmp(item.cateogary,category)==0)
        {
        printf("%-3d%-13s%-24s%-20d%-12s%-10d%-15s%s\n", i, item.name, item.cateogary, item.cost, item.quantity, item.stock, item.code,item.company);
        i++;
        j++;
        }
    }
    if(j==0)
    {   
        rechose_d:
        shop_header();
        system("cls");
        printf("No Product Found!\n1.Another Category\n2.go back\n");
        scanf("%d",&re_chose);
        switch(re_chose)
        {
            case 1:
                    goto rechose_d;
            case 2:
                    return ;
            default:
                    printf("Please select a correct number from menu.");
                    getch();
                    scanf("%c",&no);
                    goto rechose_d;        
        }
        return ;
    }
    fclose(fp);
    fp=fopen("allproducts.txt","r");
    printf("Enter name of the item you want to buy: ");
    fflush(stdin);
	gets(name);
    system("cls");
    shop_header();
    while(fread(&item,sizeof(item),1,fp)==1)
    {
        if(stricmp(item.cateogary,category)==0)
        {
            if(stricmp(item.name,name)==0)
            {
                flag=1;
                break;
            }else
            {
                flag=0;
            }
        }    
    }
    if(flag==0)
    {
        fclose(fp);
        printf("Not Found!\nPress any key to go back");
        getch();
        goto product;
    }

    if(item.stock<=0)
    {
        printf("Item out of stock!");
        getch();           
    }
    else
    {
        stock:
        system("cls");
        shop_header();
        printf("Item Name:  %s\n",item.name);
        printf("Item code:  %s\n",item.code);
        printf("Item Price: %d\n",item.cost);
        printf("Cateogary:  %s\n",item.cateogary);
        printf("Items in stock: %d\n",item.stock);
        printf("Item size: %s\n",item.quantity);
        printf("Item Company: %s\n",item.company);
        printf("\n1.Want to buy the product\n");
        printf("2.Want to add in Cart\n");
        scanf("%d",&add_or_buy_product);
        switch(add_or_buy_product)
        {
            case 1://buy product
                    printf("Enter quantity: ");
                    fflush(stdin);
                    scanf("%d",&quantity);
                    if(quantity>item.stock)
                    {   
                    qua:
                    system("cls");
                    shop_header();
                    printf("This many items are not in stock yet!\n");
                    printf("1. Re-enter quantity.\n2.Select another product\n3.Go back\n4.Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1://re-enter quantity
                                goto stock;  
                        case 2://select another product
                                fclose(fp);
                                goto product;
                        case 3://go back
                                fclose(fp);
                                return ;     
                        case 4://exit
                                exit(0);
                        default://wrong choice
                            fclose(fp);
                            printf("Please select a correct number from menu.");
                            getch();
                            goto qua;    
                        
                    }            
                    }
                    printf("Do you want to enter a discount coupon(Y/N): ");
                    fflush(stdin);
                    scanf("%c",&ch);
                    if(ch=='y'||ch=='Y')
                    {
                        discount_user(&discount);
                    }
                    price=quantity*item.cost;
                    total=total+price;
                    dis=discount*0.01; 
                    dtotal=total-total*dis;
                    strcpy(list[product_count].name,item.name);
                    list[product_count].price=item.cost;
                    list[product_count].quantity=quantity;
                    product_count++;
                    ft=fopen("temp.txt","w");
                    rewind(fp);
                    while(fread(&item,sizeof(item),1,fp)==1)
                    {
                        if(stricmp(name,item.name)!=0)
                        {       
                            fwrite(&item,sizeof(item),1,ft);
                        }
                        else if(stricmp(name,item.name)==0)
                        {
                            item.stock=item.stock-quantity;
                             fwrite(&item,sizeof(item),1,ft);                           
                        }
                    }                   
                    fclose(fp);
                    fclose(ft);
                    remove("allproducts.txt");
                    rename("temp.txt","allproducts.txt");
                    decrase_in_car_when_in_product_buy(name,quantity);                    
                    want_to_buy_product:
                    printf("\n1.Do you want to buy  product\n");
                    printf("2.Print bill\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1://want to buy another product
                                goto product;
                                break;
                        case 2://print bill
                                system("cls");
                                shop_header();
                                printf("Thank you for shopping!\n");
                                printf("Your Final reciept will be printed in... 3");
                                sleep(2);
                                printf("\b2");
                                sleep(2);
                                printf("\b1");
                                system("cls");
                                shop_header();
                                bill(list,product_count);
                                printf("\n\n\t    Total: %d\n",total);
                                printf("\t    Discount: %d\n",discount);
                                printf("\t    Total: %.2f\n",dtotal);
                                getch();
                                break;
                        default://wrong choice
                            printf("Please select a correct number from menu.");
                            getch();
                            goto want_to_buy_product;
                            break;						
                    }
                    break;
            case 2://add to cart
                    	fs=fopen("cart.txt","a+");
                     while(fread(&c,sizeof(c),1,fs)==1)
                    {
                        if(stricmp(name,c.name)==0)
                        {
                            already_cart_choice:
                            printf("Already in cart!\n1.To buy product\n2.Go back\n");
                            scanf("%d",&already_in_cart);
                            fclose(fs);
                            fclose(fp);
                            switch(already_in_cart)
                            {
                            	case 1:
                            			goto product;
                            	case 2:
										return ;
								default://wrong choice
			                            printf("Please select a correct number from menu.");
			                            getch();
			                            goto already_cart_choice;		
							}
                        }
                    }
                    rewind(fp);
                    while(fread(&item,sizeof(item),1,fp)==1)
                    {
                        if(stricmp(name,item.name)==0)
                        {    
                            strcpy(c.name,item.name);
                            strcpy(c.cateogary,item.cateogary);                           
                            strcpy(c.quantity,item.quantity);
                            strcpy(c.company,item.company);
                            strcpy(c.customer,check);
                            strcpy(c.code,item.code);
                            c.stock=item.stock;
                            c.cost=item.cost;   
                            fwrite(&c,sizeof(c),1,fs);
                            flag=0;
                            break;
                        }
                        else 
                        {
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        fclose(fp);
                        fclose(fs);
                        printf("Not Found!\nPress any key to go shop");
                        getch();
                        goto product;
                    }else
                    {
                        fclose(fp);
                        fclose(fs);
                        printf("Item successfully added in cart\npress any key to go shop");
                        getch();
                        return ;
                    }
            default://wrong choice
                    printf("Please select a correct number from menu.");
                    getch();
                    scanf("%c",&no);
                    goto stock;                   
        }
    }
}
void view_allproduct(char check[20])
{
    FILE *fp,*ft,*fs,*fst;
    struct product item;
    struct cart c;
    struct discount d;
    struct bill list[100];
    int discount=0,product_count=0,no;
    float dtotal=0,dis=0;
    int re_chose,i,j,flag=0,quantity,price,total=0,choice,add_or_buy_product,already_in_cart;
    char name[20],*ch_category,category[20],ch;
    product:
    system("cls");
    shop_header();
    fp=fopen("allproducts.txt","r");
    i=1;
    j=0;	
    printf("   Name\t\tCateogary\t\tCost\t\tsize(Kg/litre)\tStock\t  Product Code\tCompany\n");
    while(fread(&item,sizeof(item),1,fp)==1)
    {
        printf("%-3d%-13s%-24s%-20d%-12s%-10d%-15s%s\n", i, item.name, item.cateogary, item.cost, item.quantity, item.stock, item.code,item.company);
        i++;
        j=1;      
    }
    if(j<0)
    {   
        rechose_d:
        system("cls");
        printf("No Product Found!\npress any key to go back.\n");
        getch();
        return ;
    }
    fclose(fp);
    fp=fopen("allproducts.txt","r");
    printf("Enter name of the item: ");
    fflush(stdin);
    gets(name);
    while(fread(&item,sizeof(item),1,fp)==1)
    {
            if(stricmp(item.name,name)==0)
            {
                flag=1;
                break;
            }else
            {
                flag=0;
            }   
    }
    if(flag==0)
    {
        fclose(fp);
        printf("Not Found!\nPress any key to go back");
        getch();
        goto product;
    }
    if(item.stock<=0)
    {
            printf("Item Out of stock!");
            getch();
    }
    else
    {
        stock:
        system("cls");
        shop_header();
        printf("Item Name:  %s\n",item.name);
        printf("Item code:  %s\n",item.code);
        printf("Item Price: %d\n",item.cost);
        printf("Cateogary:  %s\n",item.cateogary);
        printf("Items in stock: %d\n",item.stock);
        printf("Item size: %s\n",item.quantity);
        printf("Item Company: %s\n\n",item.company);
        printf("1.Want to buy the product\n");
        printf("2.Want to add in Cart\n");
        scanf("%d",&add_or_buy_product);
        switch(add_or_buy_product)
        {
            case 1://buy product
                    printf("Enter quantity: ");
                    fflush(stdin);
                    scanf("%d",&quantity);
                    if(quantity>item.stock)
                    {   
                    qua:
                    system("cls");
                    shop_header();
                    printf("This many items are not in stock yet!\n");
                    printf("1. Re-enter quantity.\n2.Select another product\n3.Go back\n4.Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1://re-enter quantity
                                goto stock;  
                        case 2://select another product
                                fclose(fp);
                                goto product;
                        case 3://go back
                                fclose(fp);
                                return ;     
                        case 4://exit
                                exit(0);
                        default://wrong choice
                            fclose(fp);
                            printf("Please select a correct number from menu.");
                            getch();
                            scanf("%c",&no);
                            goto qua;    
                        
                    }            
                    }
                    printf("Do you want to enter a discount coupon(Y/N): ");
                    fflush(stdin);
                    scanf("%c",&ch);
                    if(ch=='y'||ch=='Y')
                    {
                        discount_user(&discount);
                    }
                    price=quantity*item.cost;
                    total=total+price;
                    dis=discount*0.01; 
                    dtotal=total-total*dis;
                    strcpy(list[product_count].name,item.name);
                    list[product_count].price=item.cost;
                    list[product_count].quantity=quantity;
                    product_count++;
                    ft=fopen("temp.txt","w");
                    rewind(fp);
                    while(fread(&item,sizeof(item),1,fp)==1)
                    {
                        if(stricmp(name,item.name)!=0)
                        {       
                            fwrite(&item,sizeof(item),1,ft);
                        }
                        else if(stricmp(name,item.name)==0)
                        {
                            item.stock=item.stock-quantity;
                             fwrite(&item,sizeof(item),1,ft);                           
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("allproducts.txt");
                    rename("temp.txt","allproducts.txt");
                    decrase_in_car_when_in_product_buy(name,quantity);                   
                    want_to_buy_product:
                     printf("\n1.Do you want to buy  product\n");
                    printf("2.Print bill\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                   switch(choice)
                    {
                        case 1://want to buy another product
                                goto product;
                                break;
                        case 2://print bill
                                system("cls");
                                shop_header();
                                printf("Thank you  for shopping!\n");
                                printf("Your Final reciept will be printed in... 3\b3");
                                sleep(2);
                                printf("\b2");
                                sleep(2);
                                printf("\b1");
                                system("cls");
                                shop_header();
                                bill(list,product_count);
                                printf("\n\n\t    Total: %d\n",total);
                                printf("\t    Discount: %d\n",discount);
                                printf("\t    Total: %.2f\n",dtotal);
                                getch();
                                break;
                        default://wrong choice
                            printf("Please select a correct number from menu.");
                            getch();
                            scanf("%c",&no);
                            goto want_to_buy_product;
                            break;						
                    }
                    break;
            case 2://add to cart
                    fs=fopen("cart.txt","a+");
                     while(fread(&c,sizeof(c),1,fs)==1)
                    {
                        if(stricmp(name,c.name)==0)
                        {
                        	already_cart_choice:
                            printf("Already in cart!\n1.To buy product\n2.Go back\n");
                            scanf("%d",&already_in_cart);
                            fclose(fs);
                            fclose(fp);
                            switch(already_in_cart)
                            {
                            	case 1:
                            			goto product;
                            	case 2:
										return ;
								default://wrong choice
			                            printf("Please select a correct number from menu.");
			                            getch();
                                        scanf("%c",&no);
			                            goto already_cart_choice;		
							}
                        }
                    }
                    rewind(fp);
                    while(fread(&item,sizeof(item),1,fp)==1)
                    {
                        if(stricmp(name,item.name)==0)
                        {    
                            strcpy(c.name,item.name);
                            strcpy(c.cateogary,item.cateogary);                           
                            strcpy(c.quantity,item.quantity);
                            strcpy(c.company,item.company);
                            strcpy(c.customer,check);
                            strcpy(c.code,item.code);
                            c.stock=item.stock;
                            c.cost=item.cost;   
                            fwrite(&c,sizeof(c),1,fs);
                            flag=0;
                            break;
                        }
                        else 
                        {
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        fclose(fp);
                        fclose(fs);
                        printf("Not Found!\nPress any key to go shop");
                        goto product;
                    }else
                    {
                        fclose(fp);
                        fclose(fs);
                        printf("Item successfully added in cart\npress any key to go shop");
                        getch();
                        return ;
                    }
            default://wrong choice
                    printf("Please select a correct number from menu.");
                    getch();
                    scanf("%c",&no);
                    goto stock;                   
        }      
    }
}
void category_select(char *category)
{	
	category_reset:
	system("cls");
    shop_header();
    int ch_category,no;
    printf("Select a category to add product in\n1.Electronic Devices\n2.Clothes\n3.Sports\n4.Home Appliances\n5.Groceries\n6.Toys\n");
    printf("Enter your choice: ");
    scanf("%d",&ch_category);
    switch(ch_category)
    {
        case 1:       
            strcpy(category,"Electronic Devices");
            break;       
		case 2:        
            strcpy(category,"Clothes");
            break;
        case 3:
            strcpy(category,"Sports");
            break;
        case 4:
            strcpy(category,"Home Appliances");
            break;
        case 5:
            strcpy(category,"Groceries");
            break;
        case 6:
            strcpy(category,"Toys");
            break;            
        default:
        
            printf("Select a correct number from menu\n");
            getch();
            scanf("%c",&no);
            goto category_reset;
            break;
        
    }
}
void ffeedback(char check[20])
{
	
    system("cls");
    printf("==================================\n");
    printf("            FEEDBACK              \n");
    printf("==================================\n");
    FILE *fp,*fn,*fs;
    struct login l;
    struct feedback feedback;
    fn=fopen("id.txt","r");
    while(fread(&l,sizeof(l),1,fn)==1)
    {     
        if(stricmp(l.id,check)==0)
        {
            fp=fopen("feedback.txt","a");
            printf("Write your feedback\n");
            strcpy(feedback.name,check);
            fflush(stdin);
            gets(feedback.f);
            fwrite(&feedback,sizeof(feedback),1,fp);
            fclose(fp);
        }
    }  
    if(stricmp(check,"owner")==0)
    { 
        fs=fopen("feedback.txt","r");
        while(fread(&feedback,sizeof(feedback),1,fs)==1)
        {  
            printf("\tUsername-%s\n%s\n",feedback.name,feedback.f);

        }
        fclose(fs);      
    }
    fclose(fn);
}
void cart(char name[20])
{
	 FILE *fp,*ft;
	 struct cart c;
     struct discount d;
     struct bill list[100];
     int discount=0,product_count=0,no;
     float dtotal=0,dis=0;
     char ch;
	 int i,j=0,re_choose,quantity,flag=0,choice,price,total=0,view_buy;
	 view_buy_c:
	 system("cls");
	 shop_header();
	 fp=fopen("cart.txt","r");
    system("cls");
    shop_header();
    i=1;
    j=0;	
    printf("   Name\t\tCateogary\t\tCost\t\tsize\tStock\t  Product Code\tCompany\n");
    while(fread(&c,sizeof(c),1,fp)==1)
    {
	        printf("%-3d%-13s%-24s%-20d%-8s%-10d%-10s%s\n", i, c.name, c.cateogary, c.cost, c.quantity, c.stock, c.code, c.company);
	        i++;
	        j=1;  
    }
    fclose(fp);
    printf("\n1.Want to Buy\n2.Go back\n");
    scanf("%d",&view_buy);
    switch(view_buy)
    {
    	case 1:
    			product:
				system("cls");
				shop_header();
				fp=fopen("cart.txt","r");
			    system("cls");
			    shop_header();
			    i=1;
			    j=0;	
			    printf("   Name\t\tCateogary\t\tCost\t\tsize\tStock\t  Product Code\tCompany\n");
			    while(fread(&c,sizeof(c),1,fp)==1)
			    {
					        printf("%-3d%-13s%-24s%-20d%-8s%-10d%-14s%s\n", i, c.name, c.cateogary, c.cost, c.quantity, c.stock, c.code, c.company);
					        i++;
					        j=1;      
			    }
			    fclose(fp);
				if(j==0)
				{   
				    rechose_d:
				    system("cls");
				    printf("No Product Found!\npress any key to go back.");
				    getch();
				    return ;
				}
				fp=fopen("cart.txt","r");
				printf("Enter name of the item: ");
				fflush(stdin);
				gets(name);
				while(fread(&c,sizeof(c),1,fp)==1)
				{
				    if(stricmp(c.name,name)==0)
			       {
			             flag=1;
			             break;
			         }   
				}
				 if(flag==0)
				 {
				     fclose(fp);
				     printf("Not Found!\nPress any key to go back");
				     goto product;
				 }
				 if(c.stock<=0)
				 {
				         printf("Item Out of stock!");
				         fclose(fp);
				         getch();
				         return;
				 }
				 else
				 {
				     stock:
				     system("cls");
				     shop_header();
				     printf("Item Name:  %s\n",c.name);
				     printf("Item code:  %s\n",c.code);
				     printf("Item Price: %d\n",c.cost);
				     printf("Cateogary:  %s\n",c.cateogary);
				     printf("Items in stock: %d\n",c.stock);
				     printf("Item size: %s\n",c.quantity);
				     printf("Item Company: %s\n\n",c.company);
				     printf("Enter quantity: ");
				     fflush(stdin);
				     scanf("%d",&quantity);
				     if(quantity>c.stock)
				     {   
			            qua:
			            system("cls");
			            shop_header();
			            printf("This many items are not in stock yet!\n");
			            printf("1. Re-enter quantity.\n2.Select another product\n3.Go back\n4.Exit\n");
			            printf("Enter your choice: ");
			            scanf("%d",&choice);
			            switch(choice)
			            {
			                case 1://re-enter quantity
			                        goto stock;  
			                case 2://select another product
			                        fclose(fp);
			                        goto product;
			                case 3://go back
			                        fclose(fp);
			                        return ;     
			                case 4://exit
			                        exit(0);
			                default://wrong choice
			                    fclose(fp);
			                    printf("Please select a correct number from menu.");
			                    getch();
                                scanf("%c",&no);
			                    goto qua;        
			            }            
				    }
				    printf("Do you want to enter a discount coupon(Y/N): ");
                    fflush(stdin);
                    scanf("%c",&ch);
                    if(ch=='y'||ch=='Y')
                    {
                        discount_user(&discount);
                    }
                    price=quantity*c.cost;
                    total=total+price;
                    dis=discount*0.01; 
                    dtotal=total-total*dis;
                    strcpy(list[product_count].name,c.name);
                    list[product_count].price=c.cost;
                    list[product_count].quantity=quantity;
                    product_count++;
					rewind(fp);
				    ft=fopen("temp.txt","w");
				    while(fread(&c,sizeof(c),1,fp)==1)
				    {
				         if(stricmp(name,c.name)!=0)
				         {       
				             fwrite(&c,sizeof(c),1,ft);
				         }
				    }
				    fclose(fp);
				    fclose(ft);
				    remove("cart.txt");
				    rename("temp.txt","cart.txt");
				    decrase_in_product_when_in_cart(name,quantity);
                    want_to_buy_product:
                      printf("\n1.Do you want to buy  product\n");
                    printf("2.Print bill\n");
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                   switch(choice)
                    {
                        case 1://want to buy another product
                                goto product;
                                break;
                        case 2://print bill
                                system("cls");
                                shop_header();
                                printf("Thank you  for shopping!\n");
                                printf("Your Final reciept will be printed in... 3");
                                sleep(2);
                                printf("\b2");
                                sleep(2);
                                printf("\b1");
                                system("cls");
                                shop_header();
                                bill(list,product_count);
                                printf("\n\n\t    Total: %d\n",total);
                                printf("\t    Discount: %d\n",discount);
                                printf("\t    Total: %.2f\n",dtotal);
                                getch();
                                break;
                        default://wrong choice
                            printf("Please select a correct number from menu.");
                            getch();
                            scanf("%c",&no);
                            goto want_to_buy_product;
					
                        }
                        break;
                        case 2:
                                return ;
                        default://wrong choice
                                printf("Please select a correct number from menu.");
                                getch();
                                scanf("%c",&no);
                                goto view_buy_c;              	     									
	            }
    }
	 
}
void decrase_in_product_when_in_cart(char check[20],int quantity)
{
    FILE *fp,*ft;
    struct product item;
    fp=fopen("allproducts.txt","r");
    ft=fopen("temp.txt","w");
    while(fread(&item,sizeof(item),1,fp)==1)
    {
        if(stricmp(check,item.name)!=0)
        {       
            fwrite(&item,sizeof(item),1,ft);
        }
        else
        {
            item.stock=item.stock-quantity;
            fwrite(&item,sizeof(item),1,ft); 
                        
        }
    }
    fclose(fp);
    fclose(ft);
 	remove("allproducts.txt");
    rename("temp.txt","allproducts.txt");
   
}
void decrase_in_car_when_in_product_buy(char check[20],int quantity)
{
    FILE *fp,*ft;
    struct cart item;
    fp=fopen("cart.txt","r");
    ft=fopen("temp.txt","w");
    while(fread(&item,sizeof(item),1,fp)==1)
    {
        if(stricmp(check,item.name)!=0)
        {       
            fwrite(&item,sizeof(item),1,ft);
        }
        else
        {
            item.stock=item.stock-quantity;
            fwrite(&item,sizeof(item),1,ft); 
                        
        }
    }
    fclose(fp);
    fclose(ft);
 	remove("cart.txt");
    rename("temp.txt","cart.txt");
   
}
void discount_company(char company_name[20])
{
	int choice_coupon,add_coupon,coupon_count=1,disc_flag=0,flag=0,no;
	struct discount d;
	FILE *fp,*ft;
	char check_disc_code[20],up_y;
	discount_menu:
	system("cls");
	discount_header();
    printf("1. Add Coupons\n");
    printf("2. View and Update Coupons\n");
    printf("3. View and Remove Coupons\n");
    printf("4. Go back to main menu\n");
    printf("Enter your choice: ");
    scanf("%d",&choice_coupon);
    switch(choice_coupon)
    {
    	case 1:
    			coupon_reset:
    			system("cls");
				discount_header();
    			printf("1.Want to add coupon\n2.Go back");
    			scanf("%d",&add_coupon);
    			switch(add_coupon)
    			{
    				case 1:
							disc_code_reset:
							system("cls");
							discount_header();
			                fp=fopen("Coupons.txt","a+");
			                fflush(stdin);
			                printf("Enter code: ");
			                gets(check_disc_code);
			                while(fread(&d,sizeof(d),1,fp)==1)
			                {
				                    if(stricmp(d.code,check_disc_code)==0)
				                    {
				                    	fclose(fp);
				                        printf("Code already exists!\nPlease enter a unique code\n");
				                        getch();
				                        goto disc_code_reset;
				                    }
			                }
			                strcpy(d.code,check_disc_code);
			                strcpy(d.company,company_name);
			                disc_reset:
			                printf("Enter discount rate: ");
			                scanf("%d",&d.discount);
			                if(d.discount>100||d.discount<0)
			                {
			                    printf("Please enter a value between 0-100\n");
			                    goto disc_reset;
			                }
			                fwrite(&d,sizeof(d),1,fp);
			                fclose(fp);
			                printf("Code successfully added!\nPress any key to go back to main menu.");
			                getch();
			                goto discount_menu;
			         case 2:
					 		goto discount_menu; 
					 default:
		                    printf("Please enter a correct number.\n");
		                    getch();
		                    scanf("%c",&no);
		                    goto coupon_reset;		       
					}
    			                break;
                case 2:
                    disc_update_retry:
      	    		system("cls");
					discount_header();
              		fp=fopen("Coupons.txt","r");
                    printf("   Name\t  Discount\n");
                    coupon_count=1;
                    while(fread(&d,sizeof(d),1,fp)==1)
                    {
                    	if(stricmp(d.company,company_name)==0)
                    	{
                        printf("%-3d%-13s%-24d\n",coupon_count,d.code,d.discount);
                        coupon_count++;
                    	}
                    }
                    fclose(fp);
                    printf("Do you want to edit a code(Y/N): ");
                    fflush(stdin);
                    scanf("%c",&up_y);
                    if(up_y=='y'||up_y=='Y')
                    {
                        fp=fopen("Coupons.txt","r");
                        ft=fopen("temp.txt","w");
                        printf("Enter code you want to edit: ");
                        fflush(stdin);
                        gets(check_disc_code);
                        system("cls");
						discount_header();
                        while(fread(&d,sizeof(d),1,fp)==1)
                        {
                        	if(stricmp(d.company,company_name)==0)
                    		{
	                            if(stricmp(d.code,check_disc_code)==0)
	                            {
	                                printf("\t\t\t------Editing %s-------\n",d.code);
	                                printf("Enter new code: ");
	                                fflush(stdin);
	                                gets(d.code);
	                                printf("Enter new rate for code: ");
	                                scanf("%d",&d.discount);
	                                strcpy(d.company,company_name);
	                                fwrite(&d,sizeof(d),1,ft);
	                                disc_flag=1;
	                            }
	                            else
	                            {
	                                fwrite(&d,sizeof(d),1,ft);
	                            }
                        	}
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("Coupons.txt");
                        rename("temp.txt","Coupons.txt");
                        if(disc_flag==1)
                        {
                            printf("Code successfully updated!\nPress any key to go back to main menu.");
                            getch();
                            goto discount_menu;
                        }
                        else
                        {
                            printf("Code not found!\nDo you want to retry(Y/N): ");
                            fflush(stdin);
                            scanf("%c",&up_y);
                            if(up_y=='Y'||up_y=='y')
                            {
                                goto disc_update_retry;
                            }
                        }
                    }
                    else
                    {
                        goto discount_menu;
                    }
                    break;
                
                case 3://delete coupon
                    disc_delete_retry:
                    system("cls");
					discount_header();
                    fp=fopen("Coupons.txt","r");
                    printf("   Coupon code\t  Discount\n");
                    coupon_count=1;
                    while(fread(&d,sizeof(d),1,fp)==1)
                    {
                    	if(stricmp(d.company,company_name)==0)
                    	{
                        	printf("%-3d%-13s%-24d\n",coupon_count,d.code,d.discount);
                            coupon_count++;
                    	}
                    }
                    fclose(fp);
                    printf("Do you want to delete a code(Y/N): ");
                    fflush(stdin);
                    scanf("%c",&up_y);
                    if(up_y=='y'||up_y=='Y')
                    {
                        fp=fopen("Coupons.txt","r");
                        ft=fopen("temp.txt","w");
                        printf("Enter code you want to delete: ");
                        fflush(stdin);
                        gets(check_disc_code);
                        while(fread(&d,sizeof(d),1,fp)==1)
                        {                                                           
                            if(stricmp(d.code,check_disc_code)==0)
                            {
                 				flag=1;               
                            }
                            else
                            {
                                fwrite(&d,sizeof(d),1,ft);
                            }
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("Coupons.txt");
                        rename("temp.txt","Coupons.txt");
                        if(flag==1)
                        {
                            printf("Code successfully removed!\nPress any key to go back to main menu.");
                            getch();
                            goto discount_menu;
                        }
                        else
                        {
                            printf("Code not found!\nDo you want to retry(Y/N): ");
                            fflush(stdin);
                            scanf("%c",&up_y);
                            if(up_y=='Y'||up_y=='y')
                            {
                                goto disc_delete_retry;
                            }
                        }
                    }
                    else
                    {
                        goto discount_menu;
                    }
                    break;
                
                case 4:
                
						return;
                
                default:
                    printf("Please enter a correct number.\n");
                    printf("Press any key to go back to main menu\n");
                    getch();
                    scanf("%c",&no);
                    goto discount_menu;
	}
}
void discount_user(int *discount)
{
    struct discount d;
    char ch,code[20];
    int coupon_flag=0,flag=0,choose;
    FILE *fp;
    re_enter_coupon:
    printf("Enter code: ");
    fflush(stdin);
    gets(code);
    fp=fopen("Coupons.txt","r");
    while(fread(&d,sizeof(d),1,fp)==1)
    {
        if(stricmp(d.code,code)==0)
        {
            *discount=d.discount;
            flag=0;
            break;
        }
        else
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        fclose(fp);
        re_choose:
        printf("\nNot Found!\n1.Want to re-enter the code\n2.Go back\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                    goto re_enter_coupon;
            case 2:
                    return ;
            default:
                    printf("\nEnter correct number");
                    getch();
                    goto re_choose;
        }
    }
    fclose(fp);
}
void bill(struct bill list[100],int product_count)
{
    int s_no=1,i;
    printf("  Name \t\t Price \t\tQuantity\n");
    for(i=0;i<product_count;i++)
    {
        printf("%d.%-15s%-15.2f%d\n",s_no,list[i].name,list[i].price,list[i].quantity);
        s_no++;
    }
}
