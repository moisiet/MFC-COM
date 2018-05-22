一，MFC实现COM组件总结起来就是五个宏：
1.创建嵌入类宏；2.动态工厂创建类宏；3.接口映射宏；4.IUnknown函数实现后；5，接口实现宏
二，调用该COM组件：
经过测试，MFC COM组件并不能与ATL COM组件一样，自动注册，然后出现在类型库中；
调用步骤为：
1.导入接口#include "IFunction"
2.注册
3.CoCreateInstace()


