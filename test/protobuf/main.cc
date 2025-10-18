#include "test.pb.h"

#include <iostream>
#include <string>

int main()
{
    // //message里面套着一个message如何使用？
    // fixbug::LoginResponse rsp;
    // fixbug::ResultCode *rc=rsp.mutable_result();
    // rc->set_errcode(0);
    // rc->set_errmsg("Login failed");
    

    
    fixbug::GetFriendListsResponse rsp;
    //mutable_message名(套在message里的单个message)的函数返回该指针(可以修改)
    //result()函数是一个只读不可修改的引用，所以用mutable_message名函数
    fixbug::ResultCode *rc=rsp.mutable_result(); 
    rc->set_errcode(0);
    
    //如何处理protobuf中的列表类型
    fixbug::User *user1= rsp.add_friend_list(); //add_列表名的函数返回新增单个列表成员的指针
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(fixbug::User::MAN);

    fixbug::User *user2= rsp.add_friend_list();
    user2->set_name("li si");
    user2->set_age(20);
    user2->set_sex(fixbug::User::MAN);
    //查看当前列表中成员个数
    std::cout<<rsp.friend_list_size()<<std::endl;
    //读取当前成员
    for(int i=0;i<rsp.friend_list_size();++i)
    {
        fixbug::User user=rsp.friend_list(i);
        std::cout<<"name :"<<user.name()<<" age: "<<user.age()<<" sex: "<<user.sex()<<std::endl;
    }
    return 0;   
}


#if 0
int main()
{
    //封装login请求对象的数据
    fixbug::LoginRequest req;
    req.set_name("zhangsan");
    req.set_pwd("123456");

    //对象数据序列化 =》string
    std::string send_str;
    if (req.SerializeToString(&send_str))
    {
        std::cout << send_str << std::endl;
    }

    //从send_str反序列化一个login请求对象
    fixbug::LoginRequest reqB;
    if(reqB.ParseFromString(send_str))
    {
        std::cout<<reqB.name()<<std::endl;
        std::cout<< reqB.pwd()<<std::endl;
    }
    return 0;
}
#endif

