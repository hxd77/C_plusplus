#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    const int N =5;
    vector<int> s(N); //定义一个大小为N的向量容器
    //从标准输入读入向量容器的内容
    for (auto& si:s)
    {
        cin>>si;
    }
    //输出向量容器中每个元素的相反数
    transform(s.begin(),s.end(),ostream_iterator<int>(cout," "),negate<int>());//用来对序列做变换
    //ostream_iterator<int>(cout, " ")这是一个 输出迭代器，用来把结果写到 cout，并在每个输出元素后加一个空格 " "。
    //negate<int>这是一个 STL 函数对象（定义在 <functional> 里），作用就是取负号：
    /*等价于for (auto x : s) cout << -x << " "; */
    cout<<endl;
    return 0;
}