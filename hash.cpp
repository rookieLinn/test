#define HASHSIZE 12
#define NULLKEY -32768

//定义一个哈希表结构
typedef struct
{
    int *elem;  //数据元素的基址，动态分配数组
    int count;  //当前数据元素个数
} HashTable;

//初始化散列表
int InitHashTable(HashTable *H)
{
    H->count = HASHSIZE;
    H->elem = (int *)malloc(HASHSIZE * sizeof(int));
    if(!H->elem)
    {
        return -1;  //申请空间失败
    }
    for(int i = 0; i < HASHSIZE; i++)
    {
        H->elem[i] = NULLKEY;   //迭代进行初始化，其中的NULLKEY是默认值
    }
    return 0;
}

//使用除留余数法
int Hash(int key)
{
    return key % HASHSIZE;  //除数一般小于等于表长
}

//插入关键字到散列表
void InsertHash(HashTable *H, int key)
{
    int addr;
    addr = Hash(key);   //得到偏移地址
    while(H->elem[addr] != NULLKEY)     //如果不为空，则冲突出现
    {
        addr = (addr + 1) % HASHSIZE;    //开放定址法的线性探测
    }
    H->elem[addr] = key;
}

//散列表查找关键字
int SearchHash(HashTable H, int key, int *addr)
{
    *addr = Hash(key);
    while(H.elem[*addr] != key)
    {
        *addr = (*addr + 1) % HASHSIZE;
        if(H.elem[*addr] == NULLKEY || *addr == Hash(key))  //若循环回到原点或不存在关键字
        {
            return -1;
        }
    }
    return 0;
}
