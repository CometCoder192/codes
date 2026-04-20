#include <iostream>
using namespace std;

const int maxsize = 20;

// Separate arrays for clarity
float wt_f[maxsize], profit_f[maxsize], pro_byw[maxsize]; // fractional
int wt[maxsize], profit[maxsize];                         // 0/1

int sack_cap;

// ---------- SORT (for fractional) ----------
void sort(int n)
{
    for(int i=0;i<n-1;i++)
     for(int j=0;j<n-1-i;j++)
        if(pro_byw[j+1]>pro_byw[j])
        {
            swap(pro_byw[j], pro_byw[j+1]);
            swap(wt_f[j], wt_f[j+1]);
            swap(profit_f[j], profit_f[j+1]);
        }
}

// ---------- FRACTIONAL KNAPSACK ----------
float fractional(int n)
{
    float tp = 0, temp_cap = sack_cap;

    for(int i=0;i<n;i++)
    {
        if(temp_cap > 0 && wt_f[i] <= temp_cap)
        {
            tp += profit_f[i];
            temp_cap -= wt_f[i];
        }
        else
        {
            tp += profit_f[i] * (temp_cap / wt_f[i]);
            break;
        }
    }
    return tp;
}

// ---------- 0/1 KNAPSACK ----------
int zero_one(int n)
{
    int pm[maxsize][maxsize];

    for(int i=0;i<=n;i++) pm[i][0]=0;
    for(int w=0;w<=sack_cap;w++) pm[0][w]=0;

    for(int i=1;i<=n;i++)
    {
        for(int w=0;w<=sack_cap;w++)
        {
            if(w >= wt[i])
                pm[i][w] = max(pm[i-1][w], pm[i-1][w-wt[i]] + profit[i]);
            else
                pm[i][w] = pm[i-1][w];
        }
    }

    return pm[n][sack_cap];
}


// ---------- MAIN ----------
int main()
{
    int n, choice;

    cout<<"1. Fractional Knapsack\n2. 0/1 Knapsack\n";
    cin>>choice;

    cout<<"Enter number of objects: ";
    cin>>n;

    cout<<"Enter capacity: ";
    cin>>sack_cap;

    if(choice == 1)
    {
        // Fractional input
        for(int i=0;i<n;i++)
        {
            cout<<"Profit "<<i<<": ";
            cin>>profit_f[i];
        }

        for(int i=0;i<n;i++)
        {
            cout<<"Weight "<<i<<": ";
            cin>>wt_f[i];
        }

        for(int i=0;i<n;i++)
            pro_byw[i] = profit_f[i] / wt_f[i];

        sort(n);

        cout<<"Max Profit = "<<fractional(n)<<endl;
    }
    else
    {
        // 0/1 input (use int)
        for(int i=1;i<=n;i++)
        {
            cout<<"Profit "<<i<<": ";
            cin>>profit[i];
        }

        for(int i=1;i<=n;i++)
        {
            cout<<"Weight "<<i<<": ";
            cin>>wt[i];
        }

        cout<<"Max Profit = "<<zero_one(n)<<endl;
    }

    return 0;
}