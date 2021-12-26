#include <iostream>
#include<string>
using std::cin;
using std::cout;
using std::string;
/**
 * @brief This structure holds the capacity, quantity and filler values of different box types
 * like, capacity[0]= S,capacity[1]= M,capacity[2]= L,capacity[3]= XL
 * quantity[0]=S,quantity[1]=M,quantity[2]=L,quantity[3]=XL. Similarly filler[].
 * 
 */
struct Boxes {
	int capacity[4];
	int quantity[4];
	int filler[4];
}box;

unsigned int get_total_parts();
void get_total_boxes(Boxes& box);
void get_parts_per_box(Boxes& box);
void fill_up_boxes(Boxes& box);

/**
 * @brief Checks whether the input is Integer or not
 * 
 * @param str 
 * @return true if it is Integer
 * @return false if it is not an Integer
 */
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}
/**
 * @brief Gets the total number of parts as an input from the user and validates the conditions of being non zero and positive.
 * 
 * @return unsigned integer value of the total number of parts
 */
unsigned int get_total_parts()
{
	int total_num_parts{};
	string str;
	cout<<"How many parts in total?:"<<" ";
	getline(cin,str);
	if(check_number(str))
	{
		total_num_parts=stoi(str);
		while(total_num_parts<=0){
			cout<<"Enter a positive integer value !"<<"\n";
			get_total_parts();
		}
		return total_num_parts;
		
	}
	else
	{
		cout<<"Enter a positive integer value"<<"\n";
		get_total_parts();
	}
	

}
/**
 * @brief Get the total boxes, takes Box structure as a parameter and takes inputs
 * from the user on the quantity of indiviual types of boxes and checks the constraints of no quantity being non zero.
 * 
 * @param Box object is the parameter to this function
 */
void get_total_boxes(Boxes& box)
{
	string total_boxes[4];
	cout<<"How many boxes for S/M/L/XL?"<<" ";
	cin>>total_boxes[0]>>total_boxes[1]>>total_boxes[2]>>total_boxes[3];
	for(int i{0};i<4;i++)
	{
		if(check_number(total_boxes[i])&&stoi(total_boxes[i])>0)
		{
			box.quantity[i]=stoi(total_boxes[i]);

		}
		else
		{
			cout<<"Enter positive integer values for quantities !"<<"\n";
			get_total_boxes(box);
			break;
		}
	}
}
/**
 * @brief Get the parts per box, takes in the user input on the capacity of each box type,
 * and checks whether it is following the standard rule S<M<L<XL. If not it asks for input again.
 * 
 * @param Box struture object is the parameter to this function.
 */
void get_parts_per_box(Boxes& box){
	string parts_per_box[4];
	cout<<"How many parts per box for S/M/L/XL?"<<" ";
	cin>>parts_per_box[0]>>parts_per_box[1]>>parts_per_box[2]>>parts_per_box[3];
	for(int i{0};i<4;i++)
	{
		if(check_number(parts_per_box[i])&& stoi(parts_per_box[i])>0)
		{
			box.capacity[i]=stoi(parts_per_box[i]);

		}
		else
		{
			cout<<"Enter positive integer values for capacities !"<<"\n";
			get_parts_per_box(box);
			break;
		}
	}
	while((box.capacity[0]<=0 || box.capacity[1]<=0 || box.capacity[2]<=0 || 
	box.capacity[3]<=0)||(box.capacity[0]>box.capacity[3]||box.capacity[0]>box.capacity[1]||
	box.capacity[0]>box.capacity[2]||box.capacity[1]>box.capacity[3]||box.capacity[1]>box.capacity[2]||
	box.capacity[2]>box.capacity[3]))
	{
		cout<<"Enter values in the order S<M<L<XL"<<"\n";
		get_parts_per_box(box);
	}
}
/**
 * @brief Fill_up_boxes, handles the filling up of each type of box according to the rules
 * it fills up in the order XL>L>M>S, and makes sure that no box is partially filled.
 * 
 * @param box struture object is the parameter to this function.
 * @param num_parts are required in order to distribute the parts among the different boxes.
 */
void fill_up_boxes(Boxes& box,int num_parts)
{
	int rem_parts=num_parts;
	cout<<"\n"<<"\n"<<"Boxes that can be built with "<<rem_parts<<" pegs: "<<"\n";
	cout<<"--------------------------------------------------------"<<"\n";
	while(rem_parts>box.capacity[0] && box.filler[0]!=box.quantity[0])
	{
		if(rem_parts>=box.capacity[3])
		{
			for(int i{1};i<=box.quantity[3];i++)
			{
				if(rem_parts>=box.capacity[3])
				{
					rem_parts-=box.capacity[3];
					box.filler[3]=i;
				}
				else 
				{
					break;
				}
			} 	
		}
		cout<<"XL box ("<<box.quantity[3] <<" x "<< box.capacity[3]<<" max): "<< box.filler[3]<< " -- "<< "remaining parts: "<< rem_parts<<"\n";
		if(rem_parts>=box.capacity[2])
		{
			for(int i{1};i<=box.quantity[2];i++)
			{
				if(rem_parts>=box.capacity[2])
				{
					rem_parts-=box.capacity[2];
					box.filler[2]=i;
				}	
				else 
				{
					break;
				}
			}
		}
		cout<<"L box ("<<box.quantity[2] <<" x "<< box.capacity[2]<<" max): "<< box.filler[2]<< " -- "<< "remaining parts: "<< rem_parts<<"\n";
		if(rem_parts>=box.capacity[1])
		{
			for(int i{1};i<=box.quantity[1];i++)
			{
				if(rem_parts>=box.capacity[1]){
					rem_parts-=box.capacity[1];
					box.filler[1]=i;
				}	
				else 
				{
					break;
				}
					
			}
		}
		cout<<"M box ("<<box.quantity[1] <<" x "<< box.capacity[1]<<" max): "<< box.filler[1]<< " -- "<< "remaining parts: "<< rem_parts<<"\n";
		if(rem_parts>=box.capacity[0])
		{
			for(int i{1};i<=box.quantity[0];i++)
			{
				if(rem_parts>=box.capacity[0])
				{
					rem_parts-=box.capacity[0];
					box.filler[0]=i;
				}
				else 
				{
					break;
				}
				
			}
		}
		cout<<"S box ("<<box.quantity[0] <<" x "<< box.capacity[0]<<" max): "<< box.filler[0]<< " -- "<< "remaining parts: "<< rem_parts<<"\n";


	}
	cout<<"Parts not in boxes: "<<rem_parts<<"\n";

}

int main(){
	int total_num_parts=get_total_parts();
	get_total_boxes(box);
	get_parts_per_box(box);
	fill_up_boxes(box,total_num_parts);
} 
