#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class shop
{
    int itemcode[50]={1,2,3,4,5};
    string itemname[50]={"Apples","Noodles","Brush","Chocolate","Pen"}; // Changeable inventory
    float itemprice[50]={100,30,20,150,10};
    int cart[50]; // stores the item's codes in user's cart
    int quantity[50];  // stores the item's quantities in user's cart
    int code, qty;
    int count = 0;
    double sum = 0.0;
    public:
    void storeDetails()
    {  
        cout<<"code"<<setw(32)<<"name"<<setw(32)<<"price"<<endl;
        for(int i = 0;i<5;i++)
        {
            cout<<itemcode[i]<<setw(32)<<itemname[i]<<setw(32)<<itemprice[i]<<endl;
        }
    }
    void getItem()
    {
       cout<< "Enter code of item and quantity to add cart"<<endl;
       cin>>code>>qty;
       
        int c = 0;
        for(int i=0;i<5;i++)
          {
            if(itemcode[i]==code)
            {
                cart[count]= code;
                quantity[count] = qty;
                cout<<"Item added in cart"<<endl;
                count++;
                
            }
          }
             
    }
    void displaySum() //display total value of all items
    {
        sum = 0.0;
        int j;
        for (int i = 0; i < count; i++) // Change the condition to i < count
        {
            for (j = 0; j < 5; j++)
            {
                if (cart[i] == itemcode[j])
                    break;
            }
            if (j < 5) // Check if an item was found in the itemcode array
            {
                sum += quantity[i] * itemprice[j];
            }
        }
        cout << "Sum of the current items: Rs." << sum << endl;
    }

    void deleteItem()
{
    cout << "Enter item code to delete item" << endl;
    cin >> code;
    int c = 0;
    int i = 0;
    int j = 0;
    int flag = 0;
    for (i = 0; i < count; i++) // Change the condition from i<=count to i<count
    {
        if (cart[i] == code)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        for (j = i; j < count - 1; j++) 
        {
            cart[j] = cart[j + 1];
            quantity[j] = quantity[j + 1];
        }
        count--; // Decrement the count to reflect the deleted item
        cout<<"Successfully Deleted Item"<<endl;
    }
    else 
        cout<< "Item to be deleted not present"<<endl;
}
    void createBill()
    {   
        int i,j;
        float inventory = 0;
        cout<< "***********************Your Generated Bill***********************"<<endl;
        cout<<"Code"<<setw(32)<<"Quantity"<<setw(32)<<"Price"<<setw(32)<<"Total"<<endl;
        for(i=0;i<count;i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (cart[i] == itemcode[j])
                    break;
            }
            cout<<cart[i]<<setw(32)<<quantity[i]<<setw(32)<<itemprice[j]<<setw(32)<<quantity[i] * itemprice[j]<<endl;
            inventory+= itemprice[j];
        }
        cout<<"Grand Total: Rs."<<sum<<endl;
        cout<<endl<<"Total value of inventory: Rs."<<inventory<<endl;
    }
};
int main()
{
    shop s;
    int c = 0;
    cout << "Welcome to shopping list for a departmental store."<<endl;
    cout<< "Items available in store :-"<<endl;
    s.storeDetails();
    do
    {
        cout<< "Enter 1 to Add an item and Quantity, 2 to Display total value, 3 to Delete an item, 4 to Display the Bill and 0 to exit"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:
                s.getItem();
            break;
            case 2:
                s.displaySum();
            break;
            case 3: 
                s.deleteItem();
            break;
            case 4:
                s.createBill();
            case 0:
                break;
            default:
                cout<<"Wrong Input"<<endl;
                            
        }
    }while(c!=0);
    cout<<"Quitting......";
}
