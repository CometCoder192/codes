#include <iostream>
using namespace std;

const int MAX = 10;   // ✅ FIX
int a[MAX][3];

int hash2(int k) { return (k % 10); }

void display();
void insert(int k);
int search(int k);
void del_item(int k);

int main()
{
    int op, key, i, res;

    for(i = 0; i < MAX; i++) {
        a[i][0] = -1;
        a[i][1] = -1;
        a[i][2] = 0;
    }

    while(1)
    {
        cout<<"1.Insert  2.Search  3.Display  4.Delete  5.Exit\n";
        cin>>op;

        switch(op)
        {
            case 1:
                cin>>key;
                insert(key);
                break;

            case 2:
                cin>>key;
                res = search(key);
                if(res != -1) cout<<"Found at "<<res<<endl;
                else cout<<"Not Found\n";
                break;

            case 3:
                display();
                break;

            case 4:
                cin>>key;
                del_item(key);
                break;

            case 5:
                return 0;
        }
    }
}


// SEARCH
int search(int k)
{
    int hk = hash2(k);

    if(a[hk][2] == 0)
        return -1;

    if(k == a[hk][0])
        return hk;

    int j = a[hk][1];

    while(j != -1)
    {
        if(a[j][0] == k)
            return j;

        j = a[j][1];
    }

    return -1;
}


// DISPLAY
void display()
{
    cout<<"Index  Key  Chain\n";

    for(int i = 0; i < MAX; i++)
    {
        cout<<i<<"   ";
        if(a[i][2]) cout<<a[i][0];
        else cout<<"-";
        cout<<"   "<<a[i][1]<<endl;
    }
}


// INSERT
void insert(int k)
{
    int i, ch, hk, counter;

    hk = hash2(k);

    if(search(k) != -1) {
        cout<<"Exists\n";
        return;
    }

    if(a[hk][2] == 0) {
        a[hk][0] = k;
        a[hk][2] = 1;
        return;
    }

    counter = 0;
    i = hk + 1;

    while(counter < MAX)
    {
        if(i == MAX) i = 0;

        if(a[i][2] == 0)
        {
            a[i][0] = k;
            a[i][2] = 1;
            break;
        }

        i++;
        counter++;
    }

    if(counter == MAX) {
        cout<<"Full\n";
        return;
    }

    ch = a[hk][1];

    if(ch == -1)
        a[hk][1] = i;
    else
    {
        while(a[ch][1] != -1)
            ch = a[ch][1];

        a[ch][1] = i;
    }
}


// DELETE
void del_item(int k)
{
    int hk = hash2(k);

    if(a[hk][2] == 0){
        cout<<"Not found\n";
        return;
    }

    if(a[hk][0] == k)
    {
        int next = a[hk][1];

        if(next == -1)
        {
            a[hk][2] = 0;
            a[hk][1] = -1;
        }
        else
        {
            a[hk][0] = a[next][0];
            a[hk][1] = a[next][1];
            a[next][2] = 0;
            a[next][1] = -1;
        }
        cout<<"Deleted\n";
        return;
    }

    int prev = hk;
    int curr = a[hk][1];

    while(curr != -1)
    {
        if(a[curr][0] == k)
        {
            a[prev][1] = a[curr][1];
            a[curr][2] = 0;
            a[curr][1] = -1;
            cout<<"Deleted\n";
            return;
        }
        prev = curr;
        curr = a[curr][1];
    }

    cout<<"Not found\n";
}