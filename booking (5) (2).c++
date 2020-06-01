#include<bits/stdc++.h>

using namespace std;

int booking(string facil_name,int t1,int t2,bool arr1[],bool arr2[])
{
	    if(arr1[t1] && arr1[t2] && facil_name == "Club House")// Checking the available slot and facility name
		{
			// checking the valid time, because the available time for club House is  10 to 22
			if((t1>=10 && t1<=22) && (t2>=10 && t2<=22))	
			{

				//if the time1 and time2 inbetween 10 to 16 slot then add slot based amount 100 per hour
				if((t1>=10 && t1<16) && (t2>=10 && t2<16))
				{
					arr1[t1]=arr1[t2] = false;//false means Club House time is Reserved 
					cout<<"Booked, Rs. "<<2*100;// Calculate the amount
				}

				//if the time1 and time2 inbetween 16 to 22 slot then add slot based amount 500 per hour	
				if((t1>=16 && t1<=22) && (t2>=16 && t2<=22))
				{
					arr1[t1]=arr1[t2] = false;//False means Club House time is Reserved 
					cout<<"Booked, Rs. "<<2*500; // Calculate the amount 
				}

				/*suppose whether the time1  and time2 slots are present in either 10 to 16
				 or 16 to 22 slots it executes the  block of code .for eg:16:00,12:00*/
				else 
				{	
					int tot = 0; // intially total amount is 0

					//if the time1 or time2 slots are present in 10 to 16 then add the slot based amount 100 per hour
					if((t1>=10 && t1<16) || (t2>=10 && t2<16))
					{
						arr1[t1]=arr1[t2] = false; //False means Club House time is Reserved 
						tot+=100;// calculate the amount
					}

					//if the time1  and time2 slots are present in 16 to 22 then add the slot based amount 500 per hour
					if((t1>=16 && t1<22)||(t2>=16 && t2<22))
					{
						arr1[t1]=arr1[t2] = false;//False means Club House time is Reserved 
						tot+=500;// calculate the amount
					}
					cout<<"Booked, Rs. "<<tot; //Print the total amount
				}
			}
			else//Suppose user enter the reserved time not available it's says to enter the valid time 
			{
					cout<<"enter the valid time";
			}
		}
		else if(facil_name == "Tennis Court") //if the facility name is Tennis Court then executes the block of code.
		{
			int flag = 0;
			
			//these loop check the user expected slot is available or not 
			for(int i=t1;i<=t2;i++) 
			{
				if(!arr2[i]) // if slot is already booked then print booking failed
				{
					cout<<"Booking Failed,Already Booked.";
					flag = 1; //it's just indication
					break;
				}
			}

			if(flag == 0)  //if flag =0 means slot is available
			{
				//these loop runs the interval of time and then book the slot
				for(int i=t1;i<=t2;i++) 
				arr2[i] = false; // false means tennis court time is reserved
				int bh = t2-t1;//calculating booking hours
				cout<<"Booked, Rs."<<bh*50; //Calulate the amount
			}
		}
		else
		{
			cout<<"Booking Failed,Already Booked.";
		}
}
int main()
{
	//this is single day booking concept
	bool arr1[24],arr2[24];// two array means two facilities and size 24 means 24hrs of time

	string first,last,facil_name;//Declare the varaibles

	int dd,yy,mm,x,y,n=0,t1,t2;char sc1,sc2;//sc1,sc2(semicolon)

	char c1,c2,c3,s1,s2;//c1,c2,c3(comma),s1,s2(minus)

	for(int i=1;i<=24;i++) //loop assign all slots are available 
	{
		arr1[i] = true;
		arr2[i] = true;
	}
	while(n<3) // (n<3) represent the sample input ,we can get the input upto to slots are available
	{
		cout<<"enter the "<<n<<"th booking:";// print the resident count

		//Get the user input as your format(eg:Club House ,2012-10-26,16:00,22:00)
		cin>>first>>last>>c1>>yy>>s1>>mm>>s2>>dd>>c2>>t1>>sc1>>x>>c3>>t2>>sc2>>y;

		facil_name = first+" "+last;//concat the string because the facility name contains space

		booking(facil_name,t1,t2,arr1,arr2);// Function call

		n++; //Increment the value of n

		cout<<"\n";
	}
	return 0;
}



UNIT TEST: