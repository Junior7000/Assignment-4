/*
Name : Mohammed Ammar Ata-Elfadeel
Department : Computer 
Class : Secand Class
*/

#include <iostream>
#include <string>

using namespace std;

class Shape //الكلاس الاب (مجرد)
{
 protected :

    int width , height , radius; //تعريف القيم 
    float pi = 3.14 ; //PI قيمة الثابت 
 public :

 void set_Width() //دالة ادخال قيمة القاعدة او العرض
 {  
    cout << "Width = ";
    cin >> width;
 }

 void set_Height() //دالة ادخال قيمة الطول او الارتفاع
 {
    cout <<"Height = ";
    cin >> height;
 }

 void set_Radius() //دالة ادخال قيمة القطر
 {
    cout << "Radius = ";
    cin >> radius;
 }

 virtual int area(void)=0; //pure virtual function

 void printArea(void) //(تعدد الاوجة)دالة تتعوض فيها دوال ايجاد المساحة للكلاسات الوارثة ومن ثم تقوم بطباعتها
 {
    cout<< this -> area() << endl;
 }

 virtual int circumference(void) = 0; //pure virtual function

 void printCircumference(void) //(تعدد الاوجة)دالة تتعوض فيها دوال ايجاد المحيط للكلاسات الوارثة من ثم تقوم بطباعتها
 {
    cout << this->circumference() << endl;
 }

};

class Polygon : public Shape //  وراثة الكلاس بوليجون من الكلاس الاب
{
 public:
     int area() //دالة ايجاد مساحة المضلع
     {
         cout << "\nThe Polygon's Area = ";
         return (radius * height * width);
    }
    int circumference() //دالة ايجاد محيط المضلع
    {
        cout << "The Polygon's Circumference = ";
        return(width*height);
    }
};

class Triangle : public Polygon //وراثة الكلاس تراينجل من الكلاس بولبيجون ليصبح ابن له
{
    int area() //دالة ايجاد مساحة المثلث
    {
        cout << "\nThe Triangle's Area = ";
        return (width * height / 2);
    }
    int circumference() //دالة ايجاد محيط المثلث
    {
        cout << "The Triangle's Circumference = ";
        return (width + height*2);
    }
};

class Rectangle : public Polygon //وراثة الكلاس ريكتانجيل من الكلاس بولبيجون ليصبح ابن له
{
    int area() //دالة ايجاد مساحة المستطيل
    {
        cout << "\nThe Rectangle's Area = ";
        return (width * height);
    }
    int circumference() //دالة ايجاد محيط المستطيل
    {
        cout << "The Rectangle's Circumference = ";
        return (2*(height*width));
    }
};

class Square : public Polygon //وراثة الكلاس اسكويير من الكلاس بولبيجون ليصبح ابن له
{
    int area() //دالة ايجاد مساحة المربع
    {
        cout << "\nThe Square's Area = ";
        return (height * height);
    }
    int circumference() //دالة ايجاد محيط المربع
    {
        cout << "The Square's Circumference = ";
        return (4*height);
    }
};

class Ellipse : public Shape //وراثة الكلاس اليبس من الكلاس الاب
{
 public:
     int area() //دالة ايجاد مساحة القطع الناقص
     {
         cout << "\nThe Ellipse's Area = ";
         return (pi * width * height);
    }
    int circumference() //دالة ايجاد محيط القطع الناقص
    {
        cout << "The Ellipse's Circumference = ";
        return (pi*(radius*radius));
    }
};
class Circle : public Ellipse //وراثة الكلاس سييركل من الكلاس اليبس ليصبح ابن له
{
 public:
    int area() //دالة ايجاد مساحة الدائرة
    {
        cout << "\nThe Circle's Area = ";
        return (pi/4*(radius*radius)); 
    }
    int circumference() //دالة ايجاد محيط الدائرة
    {

        cout << "The Circle's Circumference = ";
        return (pi * radius);
    }
};
int main() //الدالة الرئيسية
{

    Polygon polygon ; Triangle triangle ; Rectangle rectangle ; Square square ; Ellipse ellipse ; Circle circle; //objects
    Shape   *pointer1 = &polygon;   //تعريف المؤشر الاول من الكلاس الاب وربطة بعنوان الكلاس بوليجون
    Shape *pointer2 = &ellipse;     //تعريف المؤشر الثاني من الكلاس الاب وربطة بعنوان الكلاس اليبس
    Polygon *pointer3 = &triangle;  //تعريف المؤشر الثالث من الكلاس بوليجون وربطة بعنوان الكلاس تراينجل
    Polygon *pointer4 = &rectangle; //تعريف المؤشر الرابع من الكلاس يوليجون وربطة بعنوان الكلاس بوليجون
    Polygon *pointer5 = &square;    //تعريف المؤشر الخامس من الكلاس بوليجون وربطة بعنوان الكلاس اسكويير
    Ellipse *pointer6 = &circle;    //تعريف المؤشر السادس من الكلاس اليبس وربطة بعنوان الكلاس سييركل

    cout << "<========FIND AREA & CIRCUMFERENCE OF SHAPES========>\n"; //واجهة البرنامج

    cout << "\nEnter The Value of Polygon's Width , Height and Radius:\n"; //ادخال القيم الخاصة لايجاد مساحة و محيط المضلع وطبعتها
    pointer1->set_Width();
    pointer1->set_Height();
    pointer1->set_Radius();
    pointer1->printArea();
    pointer1->printCircumference();

    cout << "\nEnter The Value of Ellipse's Width , Height and Radius:\n"; //ادخال القيم الخاصة لايجاد مساحة و محيط القطع الناقص وطبعتها
    pointer2->set_Width();
    pointer2->set_Height();
    pointer2->set_Radius();
    pointer2->printArea();
    pointer2->printCircumference();

    cout << "\nEnter The Value of Triangle's Width and Height:\n"; //ادخال القيم الخاصة لايجاد مساحة و محيط المثلث وطبعتها
    pointer3->set_Width();
    pointer3->set_Height();
    pointer3->printArea();
    pointer3->printCircumference();

    cout << "\nEnter The Value of Rectangle's Width and Height:\n"; //ادخال القيم الخاصة لايجاد مساحة و محيط المستطيل وطبعتها
    pointer4->set_Width();
    pointer4->set_Height();
    pointer4->printArea();
    pointer4->printCircumference();

    cout << "\nEnter The Value of Square's Height:\n"; //ادخال القيم الخاصة لايجاد مساحة و محيط المربع وطبعتها
    pointer5->set_Height();
    pointer5->printArea();
    pointer5->printCircumference();

    cout << "\nEnter The Value of Circle's Radius:\n"; //ادخال القيم الخاصة لايجاد مساحة و محيط الدائرة وطبعتها
    pointer6->set_Radius();
    pointer6->printArea();
    pointer6->printCircumference();

    cout << "\n<==============THE FINAL RESULT==============>\n"; //عملية طباعة النتيجة النهائية لمساحة ومحيط جميع الاشكال

    //طباعة النتائج الخاصة بالمضلع
    cout << "POLYGON :";  
    pointer1->printArea();
    pointer1->printCircumference();
    
    //طباعة النتائج الخاصة بالقطع الناقص
    cout << "\nELLIPSE :";
    pointer2->printArea();
    pointer2->printCircumference();
    
    //طباعة النتائج الخاصة بالمثلث
    cout << "\nTRIANGLE :";
    pointer3->printArea();
    pointer3->printCircumference();
    
    //طباعة النتائج الخاصة بالمستطيل
    cout << "\nRECTANGLE :";
    pointer4->printArea();
    pointer4->printCircumference();
    
    //طباعة النتائج الخاصة بالمربع
    cout << "\nSQUARE :";
    pointer5->printArea();
    pointer5->printCircumference();
    
    //طباعة النتائج الخاصة بالدائرة
    cout << "\nCIRCLE :";
    pointer6->printArea();
    pointer6->printCircumference();
}