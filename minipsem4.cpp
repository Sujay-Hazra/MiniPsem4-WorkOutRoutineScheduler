#include"iostream"
#include<conio.h>
#include<time.h>
using namespace std;
int temp=0,today;
inline int dayofweek(int d, int m, int y) //tomohiko sakamoto algo
{ 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    y -= m < 3; 
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7; 
}
void dispwk()
{
	cout<<"1.Biceps 2.Chest 3.Shoulders 4.Triceps 5.Back 6.Legs"<<endl;
}; 
class workouts
{
  public:
   int dayno[6],workno[6];
  string day[6], workout[6];
  public:
  		 void setup(int a,int b)
  		 {  
  		 	a=a+1;
  		   	dayno[temp]=a;
  		 	workno[temp]=b;
  		 	 if(a==1)
  		 	 day[temp]="Monday";
  		 	 if(a==2)
  		 	 day[temp]="Tuesday";
  		 	 if(a==3)
  		 	 day[temp]="Wednesday";
  		 	 if(a==4)
  		 	 day[temp]="Thursday";
  		 	 if(a==5)
  		 	 day[temp]="Friday";
  		 	 if(a==6)
  		 	 day[temp]="Saturday";
  		 	 if(b==1)
  		 	 workout[temp]="Biceps";
  		 	 if(b==2)
  		 	 workout[temp]="Chest";
  		 	 if(b==3)
  		 	 workout[temp]="Shoulders";
  		 	 if(b==4)
  		 	 workout[temp]="Triceps";
  		 	 if(b==5)
  		 	 workout[temp]="Back";
  		 	 if(b==6)
  		 	 workout[temp]="Legs";
  		 	 temp++;
  		   }
};
class wkt:public workouts
{
	int complete[5];
	public:
			wkt()
			{
				for(int j=0;j<5;j++)
				 {
				  complete[j]=0;
			     }
	     	}
	     	int submenu()
	     	{
	     	  	int a,b,count=0;
	     	  	string wokkk;
	     		string wouts[6];
	     		wouts[0]="Biceps";
	     		wouts[1]="Chest";
	     		wouts[2]="Shoulders";
	     		wouts[3]="Triceps";
	     		wouts[4]="Back";
	     		wouts[5]="Legs";
	     	   cout<<"Select An Option:\n1. Workout Completed(select 1 to mark if you have completed current workout)\n2.Reschedule Workouts\n3.Refresh\n4.Exit"<<endl;
	           cin>>a;
	    		if(a==1)
	    		{
	    			if(today==0)
	    		{
					cout<<"No workouts to complete"<<endl;
	    			getch();
	    		}
	    			else
	    		{
					
	    			if(complete[today-1]==0)
	    			 {
					 complete[today-1]=1;
	    			 return 1;
	    			}
	    			else
	    			{
					 cout<<"Workout already complete"<<endl;
					 getch();
	    			 return 1;
	    			}
	    		}
				}
				else if(a==3)
				 return 1;
				else if(a==4)
				 return 0;
				else if(a==2)
				{
				  siss: system("cls");
				  cout<<"Displaying Current Schedule :"<<endl;
				  cout<<"DAY:\t\tWORKOUT:"<<endl;
				  for(int i=0;i<6;i++)
				  {
				  	cout<<i+1<<"."<<day[i]<<"\t\t"<<workout[i]<<endl;
				  }
				  cout<<"Choose which day to be changed(1-6) *0 to cancel"<<endl;
				  cin>>temp;
				  if(temp==0)
				   return 1;
				   if(temp>6)
				{
					cout<<"Enter Proper Day"<<endl;
					getch();
					goto siss;
				}
				  temp=temp-1;
				  cout<<"Choose Workout to replace previous one"<<endl;
				  dispwk();
				  cin>>wokkk;
				  for(int k=0;k<6;k++)
				  {
				  	if(wokkk==wouts[k])
				  	  {
						count=1;
						b=k;
						break;
					}
				}
				  if(count==0)
				   {
				   cout<<"Workout not found"<<endl;
				   getch();
				   return 1;
					}
					b++;
				  setup(temp,b);
				  cout<<"Successfully updated"<<endl;
				  getch();
				  return 1;
				}
				
    }
    friend void display(wkt);
};
				void display(wkt obu)
			{
				time_t theTime = time(NULL);
				struct tm *aTime = localtime(&theTime);
				int da = aTime->tm_mday;
				int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
				int year = aTime->tm_year + 1900;
				today=dayofweek(da,month,year);
				system("cls");
				if(today==0)
				 {
				  cout<<"Today is Sunday, No workout today"<<endl;
				 }
				else
			  {
				cout<<"Today is "<<obu.day[today-1]<<"\nYour workout is : "<<obu.workout[today-1]<<endl;
				if(obu.complete[today-1]==0)
				 cout<<"Workout not completed yet"<<endl;
				else
				 cout<<"Workout Complete"<<endl;
			  }
			   	cout<<"\n\nUPCOMING WORKOUT:\n";
				if(today==6)
				 {
				 cout<<"Tomorrow is sunday, No workout tomorrow"<<endl;
				 goto mis;
				 }
				else
				{
				cout<<"Tomorrow is "<<obu.day[today]<<"\n\nWorkout for tomorrow is : "<<obu.workout[today]<<endl;
				mis: cout<<"\n\nMissed Workout:\n";
				for(int i=0;i<today-1;i++)
				{
					if(obu.complete[i]==0)
					cout<<obu.day[i]<<" - "<<obu.workout[i]<<endl;
				}
			   }
		      
			};
int main()
{
 wkt ob;
 int x,l=1;
 cout<<"Welcome to Workouts Scheduler\n\nENTER YOUR WORKOUT SCHEDULE ACCORDING TO DAYS\nDAY1-Monday\nDAY2-Tuesday\nDAY3-Wednesday\nDAY4-Thursday\nDAY5-Friday\nDAY6-Saturday\n\n*Workouts can be rescheduled hence errors not permanent\n\n";
  for(int i=0;i<6;i++)
  {
    w: cout<<"\nChoose workout for Day"<<i+1<<endl;
    dispwk();
    cin>>x;
    if(x>0 && x<7)
    {
        ob.setup(i,x);
    	cout<<"Workout Selected:"<<ob.workout[i]<<"\nEnter Next"<<endl;
	}
    else
    {
     cout<<"Wrong Input, Ener AGAIN!!\n";
     goto w;
    }
   }
 system("cls");
 cout<<"Workouts Initialized Succesfully"<<endl;
 getch();
 system("cls");
 while(l)
 {
  display(ob);
  l=ob.submenu();
 }
 system("cls");
 cout<<"Thanks For Using Workouts Schedular\n\nCreated by SUJAY HAZRA"<<endl;
 getch();
 exit(0);
}
