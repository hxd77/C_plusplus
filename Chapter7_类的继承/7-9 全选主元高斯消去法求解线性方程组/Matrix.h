//Matrix.h 文件一，Matrix类定义
#ifndef _MATRIX_H
#define _MATRIX_H
class Matrix{       //基类Matrix定义
public:
    Matrix(int size=2);     //外部接口
    ~Matrix();              //析构函数
    void setMatrix(const double*values);    //矩阵赋初值
    void printMatrix() const;               //显示矩阵
    int getSize() const {return size;}                    //得到矩阵大小
    double &element(int i,int j){return elements[i*size+j];}        //返回引用可以修改
    double element(int i,int j) const {return elements[i*size+j];}    //常对象返回不能修改
private:
    int size;           //矩阵大小
    double*elements;    //矩阵存放数组首地址
    
};
#endif