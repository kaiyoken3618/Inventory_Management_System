#include <iostream>
#include <iterator>
#include <map>
#include <list>
#include<vector>
#include <iomanip>


using namespace std;


int available_money = 0;

class Product
{
public:
    string name;
    int buy_price;
    int sell_price;
    int available_number_product;
    int total_profit;
};
vector <Product> p;

Product Add(Product p1)
{
    cout<<"Name :";
    cin >> p1.name;
    cout<<"Buy Price :";
    cin >> p1.buy_price;
    cout<<"Sell Price :";
    cin >> p1.sell_price;
    cout<<"Available number of product in inventory :";
    cin >> p1.available_number_product;
    cout<<"Total Profit Selling the Product :";
    cin >> p1.total_profit;

    return p1;

}
void Delete(string nam,int i)
{
    for(int j=i+1; j<p.size(); j++)

    {
        swap(p[j],p[j-1]);
    }
    p.pop_back();


}
void Buy(string buy,int b,int i)
{

    int limit =0;
    limit = p[i].buy_price * b;
    if(available_money >= limit)
    {
        p[i].available_number_product += b;
        available_money -= (b*p[i].buy_price);
    }
    else
    {
        cout << "Not enough available money";
    }



}
void Sell(string sell, int s,int i)
{

    if(s <= p[i].available_number_product)
    {
        p[i].available_number_product -= s;
        int profit = s*(p[i].sell_price - p[i].buy_price);
        p[i].total_profit += profit;
        available_money += (s * p[i].sell_price);
    }
    else
    {
        cout << "Not Enough item in the inventory";
    }

}
void See_List()
{
    cout << "\t"<< "[Product Name]";
    cout << "\t"<< "[Available Number of Product]";
    cout << "\t"<< "[Total Profit]";


    for(int i=0; i<p.size(); i++)
    {
        cout << " " << endl;
        cout << "\t"<< p[i].name;
        cout << "\t\t"<< p[i].available_number_product;
        cout << "\t\t\t\t"<< p[i].total_profit;
    }

}
void See_Balance()
{
    cout << "available balance =" << available_money;
}
int main()
{
    string nam;
    string buy;
    string sell;
    int c;
    int b;
    int s;
    int del_flag = 0;
    int buy_flag = 0;
    int sell_flag = 0;

    while(true)
    {


        char c;


        Product p1;

        cout << " " <<endl;
        cout << "1 -> Add" << endl;
        cout << "2 -> Delete" << endl;
        cout << "3 -> Buy" << endl;
        cout << "4 -> Sell" << endl;
        cout << "5 -> See List" << endl;
        cout << "6 -> See Balance" << endl;

        cout << "Enter your choice:" << endl;
        cin >> c;

        if(c == '1')
        {
            Product p_vec = Add(p1);
            p.push_back(p_vec);
            /*for(int j=0;j<p.size();j++)
            {
                int prof = p[j].sell_price - p[j].buy_price;
                int item = p[j].total_profit / prof;
                available_money = item * p[j].sell_price;
            }*/
        }
        else if(c == '2')
        {
            cout << "Enter product name you want to delete:";
            cin >>  nam;


            for(int k=0; k<p.size(); k++)
            {
                if(nam == p[k].name)
                {
                    del_flag = 1;
                    Delete(nam,k);
                    break;
                }
            }
            if(del_flag == 0 || p.empty())
            {
                cout << "No matching product is found";
            }

        }
        else if(c == '3')
        {
            cout << "Enter the product name from the inventory you want to buy:";
            cin >> buy;
            for(int i=0; i<p.size(); i++)
            {
                if(buy == p[i].name)
                {
                    buy_flag = 1;
                    cout << "Number of products to buy:";
                    cin >> b;
                    Buy(buy,b,i);
                    break;
                }


            }
            if(buy_flag == 0)
            {
                cout << "No matching product is found";
            }


        }
        else if(c == '4')
        {
            cout <<  "Enter the product name from the inventory you want to sell:";
            cin >> sell;
            for(int l=0; l<p.size(); l++)
            {
                if(sell == p[l].name)
                {
                    sell_flag = 1;
                    cout << "Number of products to sell:";
                    cin >> s;
                    Sell(sell,s,l);
                    break;
                }
            }
            if(sell_flag == 0)
            {
                cout << "No matching product is found";
            }


        }
        else if(c == '5')
        {
            See_List();
        }
        else if(c == '6')
        {
            See_Balance();
        }
    }
    return 0;
}
