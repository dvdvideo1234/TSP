#ifndef __VECTOR3__H_
    #define __VECTOR3__H_
    #include "mytypes.h"
    #include "common.h"

    typedef class Vec
    {
        private:
            u32 Key;
            f32 X;
            f32 Y;
            f32 Z;
            u8 *Name;
            class Vec *pNext;
        public:
            friend Vec  operator+ (Vec,  Vec);
            friend Vec  operator- (Vec,  Vec);
            friend void operator+=(Vec&, Vec);
            friend void operator-=(Vec&, Vec);
            friend Vec  operator^ (Vec,  Vec);
            friend void operator^=(Vec&, Vec);
            friend f32  operator* (Vec,  Vec);
            friend Vec  operator* (f32,  Vec);
            friend Vec  operator* (Vec,  f32);
            friend void operator*=(Vec&, f32);
            friend void operator*=(Vec&, Vec);
            friend Vec  operator/ (Vec,  f32);
            friend void operator/=(Vec&, f32);
            friend u8   operator==(Vec, Vec);
            friend u8   operator!=(Vec, Vec);
            friend u8   operator>=(Vec, Vec);
            friend u8   operator<=(Vec, Vec);
            friend u8   operator> (Vec, Vec);
            friend u8   operator< (Vec, Vec);
            friend void operator++(Vec&, s32);
            friend void operator--(Vec&, s32);
            friend void operator++(Vec&);
            friend void operator--(Vec&);
            f32         getDisByOrigin(class Vec *O);
            f32         getDisByOrigin(class Vec O);
            f32         getDisByOrigin(void);
            Vec&           DirByOrigin(class Vec *O);
            Vec&           DirByOrigin(class Vec O);
            Vec&           DirByOrigin(void);
            class Vec   getDirByOrigin(class Vec *O);
            class Vec   getDirByOrigin(class Vec O);
            class Vec   getDirByOrigin(void);
            f32         getX(){ return X; };
            f32         getY(){ return Y; };
            f32         getZ(){ return Z; };
            u32         getKey(){ return Key; };
            u8         *getName(){ return Name; };
            class Vec  *getNext(){ return pNext; };
            Vec&        setX(f32 x){ X = x; return *this; };
            Vec&        setY(f32 y){ Y = y; return *this; };
            Vec&        setZ(f32 z){ Z = z; return *this; };
            Vec&        setKey(u32 k){ Key = k; return *this; };
            Vec&        setName(const char *p);
            Vec&        setNext(class Vec *Next){ pNext = Next; return *this; };
            class Vec   getOrtogonal(class Vec *V);
            Vec&           Normalize(void);
            class Vec   getNormalized(void);
            f32         getAngleDeg(class Vec *V);
            f32         getAngleDeg(class Vec  V);
            f32         getAngleRad(class Vec *V);
            f32         getAngleRad(class Vec  V);
            class Vec   getProjected(class Vec *V);
            Vec&           Add(class Vec *V);
            Vec&           Add(class Vec  V);
            class Vec   getAdd(class Vec *V);
            class Vec   getAdd(class Vec V);
            Vec&           Sub(class Vec *V);
            Vec&           Sub(class Vec  V);
            class Vec   getSub(class Vec *V);
            class Vec   getSub(class Vec V);
            f32         getDirCos(u8);
            Vec&           Neg(void);
            class Vec   getNeg(void);
            Vec&           Mul(f32 Num);
            class Vec   getMul(f32 Num);
            Vec&           Div(f32 Num);
            class Vec   getDiv(f32 Num);
            Vec&           Set(class Vec  V);
            Vec&           Set(class Vec *V);
            Vec&           Set(f32 x, f32 y, f32 z);
            Vec&           Set(f32 x, f32 y);
            Vec&           Set(f32 x);
            f32         getAbs(void);
            Vec&           Offset(class Vec  Dir, f32 Num);
            Vec&           Offset(class Vec *Dir, f32 Num);
            class Vec   getOffset(class Vec  Dir, f32 Num);
            class Vec   getOffset(class Vec *Dir, f32 Num);
            Vec&           Cross(class Vec *V);
            Vec&           Cross(class Vec  V);
            class Vec   getCross(class Vec *V);
            class Vec   getCross(class Vec  V);
            f32         getDot(class Vec *V);
            f32         getDot(class Vec  V);
            Vec&           RollR(void);
            class Vec   getRollR(void);
            Vec&           RollL(void);
            class Vec   getRollL(void);
            Vec&           Swap(const char* Comp);
            class Vec   getSwap(const char* Comp);
            void           Print(void);
            void           PrintTrajectory(void);
                           Vec(const char *N, f32 x, f32 y, f32 z, u32 k, class Vec *Next);
                           Vec(const char *N, f32 x, f32 y, f32 z, class Vec *Next);
                           Vec(const char *N, f32 x, f32 y, f32 z);
                           Vec(const char *N);
                           Vec(f32 x, f32 y, f32 z);
                           Vec(f32 x, f32 y);
                           Vec(f32 x);
                           Vec();
                          ~Vec();
    } cVec;

    void Vec::Print(void)
    {
        printf("\rVec %p > %p --> %s, %u\n\rXYZ = { %10.4f, %10.4f, %10.4f }\n\r\n\r",
           this,pNext,Name,Key,X,Y,Z);
    }

    void Vec::PrintTrajectory(void)
    {
        cVec *V = this;
        while(V != NULL)
        {
            V->Print();
            V = V->getNext();
        }
    }

    Vec::Vec(const char *N, f32 x, f32 y, f32 z, u32 k, class Vec *Next)
    {
        X = x;
        Y = y;
        Z = z;
        Key = k;
        Name = (u8*)N;
        pNext = Next;
    }

    Vec::Vec(const char *N, f32 x, f32 y, f32 z, class Vec *Next)
    {
        X = x;
        Y = y;
        Z = z;
        Key = 0;
        Name = (u8*)N;
        pNext = Next;
    }
    Vec::Vec(const char *N)
    {
        X = 0;
        Y = 0;
        Z = 0;
        Key = 0;
        Name = (u8*)N;
        pNext = NULL;
    }

    Vec::Vec(const char *N, f32 x, f32 y, f32 z)
    {
        X = x;
        Y = y;
        Z = z;
        Key = 0;
        Name = (u8*)N;
        pNext = NULL;
    }

    Vec::Vec(f32 x, f32 y, f32 z)
    {
        X = x;
        Y = y;
        Z = z;
        Key = 0;
        Name = (u8*)"XYZ";
        pNext = NULL;
    }

    Vec::Vec(f32 x, f32 y)
    {
        X = x;
        Y = y;
        Z = 0;
        Key = 0;
        Name = (u8*)"XY";
        pNext = NULL;
    }

    Vec::Vec(f32 x)
    {
        X = x;
        Y = 0;
        Z = 0;
        Key = 0;
        Name = (u8*)"X";
        pNext = NULL;
    }

    Vec::Vec()
    {
        X = 0;
        Y = 0;
        Z = 0;
        Key = 0;
        pNext = NULL;
    }

    Vec::~Vec()
    {
        free(Name);
    }

    f32 Vec::getDisByOrigin(class Vec *O)
    {
        if(O != NULL)
        {
            return RootIter((X - O->getX()) * (X - O->getX()) +
                            (Y - O->getY()) * (Y - O->getY()) +
                            (Z - O->getZ()) * (Z - O->getZ()),0.00001,100);
        }else{
            return RootIter(X*X + Y*Y + Z*Z,0.00001,100);
        }
    }


    f32 Vec::getDisByOrigin(class Vec O)
    {
       return RootIter((X - O.getX()) * (X - O.getX()) +
                       (Y - O.getY()) * (Y - O.getY()) +
                       (Z - O.getZ()) * (Z - O.getZ()),0.00001,100);
    }

    f32 Vec::getDisByOrigin(void)
    {
        return RootIter(X*X + Y*Y + Z*Z,0.00001,100);
    }

    Vec Vec::getDirByOrigin(class Vec *O)
    {
        f32 D;
        if(O != NULL)
        {
            D = getDisByOrigin(O);
            if(D != 0)
            {
                return Vec("DIRORG",(X - O->getX()) / D,
                                    (Y - O->getY()) / D,
                                    (Z - O->getZ()) / D);
            }
            return Vec("FAIL",0,0,0);
        }else{
            D = getDisByOrigin(NULL);
            if(D != 0)
            {
                return Vec("DIRORG",X / D,Y / D,Z / D);
            }
            return Vec("FAIL",0,0,0);
        }
    }

    Vec Vec::getDirByOrigin(class Vec O)
    {
        f32 D = getDisByOrigin(&O);
        if(D != 0)
        {
            return Vec("DIRORG",(X - O.getX()) / D,
                                (Y - O.getY()) / D,
                                (Z - O.getZ()) / D);
        }
        return Vec("FAIL",0,0,0);
    }

    Vec Vec::getDirByOrigin(void)
    {
        f32 D = getDisByOrigin(NULL);
        if(D != 0)
        {
            return Vec("DIRORG",X / D,
                                Y / D,
                                Z / D);
        }
        return Vec("FAIL",0,0,0);
    }

    Vec& Vec::DirByOrigin(class Vec *O)
    {
        f32 D;
        if(O != NULL)
        {
            D = getDisByOrigin(O);
            if(D != 0)
            {
                setX((X - O->getX()) / D);
                setY((Y - O->getY()) / D);
                setZ((Z - O->getZ()) / D);
            }
        }else{
            D = getDisByOrigin(NULL);
            if(D != 0)
            {
                setX(X / D);
                setY(Y / D);
                setZ(Z / D);
            }
        }
        return *this;
    }

    Vec& Vec::DirByOrigin(class Vec O)
    {
        f32 D = getDisByOrigin(&O);
        if(D != 0)
        {
            setX((X - O.getX()) / D);
            setY((Y - O.getY()) / D);
            setZ((Z - O.getZ()) / D);
        }
        return *this;
    }

    Vec& Vec::DirByOrigin(void)
    {
        f32 D = getDisByOrigin(NULL);
        if(D != 0)
        {
            setX(X / D);
            setY(Y / D);
            setZ(Z / D);
        }
        return *this;
    }

    Vec operator^(Vec a, Vec b)
    {
        return a.getCross(&b);
    }

    f32 operator*(Vec a, Vec b)
    {
        return a.getDot(&b);
    }

    Vec operator+(Vec a, Vec b)
    {
          return  Vec("+",a.getX() + b.getX(),
                          a.getY() + b.getY(),
                          a.getZ() + b.getZ());
    }

    Vec operator-(Vec a, Vec b)
    {
          return  Vec("-",a.getX() - b.getX(),
                          a.getY() - b.getY(),
                          a.getZ() - b.getZ());
    }

    void operator+=(Vec &a, Vec b)
    {
        a.setX(a.getX() + b.getX());
        a.setY(a.getY() + b.getY());
        a.setZ(a.getZ() + b.getZ());
    }

    void operator^=(Vec &a, Vec b)
    {
        cVec C;
        C = a.getCross(&b);
        a.Set(&C);
    }

    void operator*=(Vec &a, Vec b)
    {
        f32 Dot = a.getDot(&b);
        a.Mul(Dot);
    }

    void operator-=(Vec &a, Vec b)
    {
        a.setX(a.getX() - b.getX());
        a.setY(a.getY() - b.getY());
        a.setZ(a.getZ() - b.getZ());
    }

    Vec operator*(f32 a, Vec b)
    {
        return Vec("*",a * b.getX(),
                       a * b.getY(),
                       a * b.getZ());
    }

    Vec operator*(Vec b, f32 a)
    {
        return Vec("*",a * b.getX(),
                       a * b.getY(),
                       a * b.getZ());
    }

    Vec  operator/(Vec b, f32 a)
    {
        if(a != 0)
        {
            return Vec("/",b.getX() / a,
                           b.getY() / a,
                           b.getZ() / a);
        }
        return Vec("FAIL",0,0,0);
    }

    void operator*=(Vec &a, f32 b)
    {
        a.setX(a.getX() * b);
        a.setY(a.getY() * b);
        a.setZ(a.getZ() * b);
    }

    void operator/=(Vec &a, f32 b)
    {
        if(b != 0)
        {
            a.setX(a.getX() / b);
            a.setY(a.getY() / b);
            a.setZ(a.getZ() / b);
        }
    }

    u8 operator==(Vec a, Vec b)
    {
        if((a.getX() == b.getX()) &&
           (a.getY() == b.getY()) &&
           (a.getZ() == b.getZ()))
            return 0xFF;
        return 0x00;
    }

    u8 operator!=(Vec a, Vec b)
    {
        if((a.getX() != b.getX()) ||
           (a.getY() != b.getY()) ||
           (a.getZ() != b.getZ()))
            return 0xFF;
        return 0x00;
    }

    u8 operator>=(Vec a, Vec b)
    {
        if(a.getAbs() >= b.getAbs())
            return 0xFF;
        return 0x00;
    }

    u8 operator<=(Vec a, Vec b)
    {
        if(a.getAbs() <= b.getAbs())
            return 0xFF;
        return 0x00;
    }

    u8 operator>(Vec a, Vec b)
    {
        if(a.getAbs() > b.getAbs())
            return 0xFF;
        return 0x00;
    }

    u8 operator<(Vec a, Vec b)
    {
        if(a.getAbs() < b.getAbs())
            return 0xFF;
        return 0x00;
    }

    void operator++(Vec &v, s32 a)
    {
       cVec Dr;
       Dr = v.getDirByOrigin(NULL);
       v.setX(v.getX() + Dr.getX());
       v.setY(v.getY() + Dr.getY());
       v.setZ(v.getZ() + Dr.getZ());
    }

    void operator--(Vec &v, s32 a)
    {
       cVec Dr;
       Dr = v.getDirByOrigin(NULL);
       v.setX(v.getX() - Dr.getX());
       v.setY(v.getY() - Dr.getY());
       v.setZ(v.getZ() - Dr.getZ());
    }

    void operator++(Vec &v)
    {
       cVec Dr;
       Dr = v.getDirByOrigin(NULL);
       v.setX(v.getX() + Dr.getX());
       v.setY(v.getY() + Dr.getY());
       v.setZ(v.getZ() + Dr.getZ());
    }

    void operator--(Vec &v)
    {
       cVec Dr;
       Dr = v.getDirByOrigin(NULL);
       v.setX(v.getX() - Dr.getX());
       v.setY(v.getY() - Dr.getY());
       v.setZ(v.getZ() - Dr.getZ());
    }

    Vec& Vec::setName(const char *p)
    {
        free(Name);
        Name = (u8*)p;
        return *this;
    }

    Vec& Vec::Normalize(void)
    {
        DirByOrigin();
        return *this;
    }
    Vec Vec::getNormalized(void)
    {
        return getDirByOrigin();
    }

    f32 Vec::getAbs()
    {
        return RootIter(X*X + Y*Y + Z*Z,0.00001,100);
    }

    f32 Vec::getAngleRad(class Vec *V)
    {
        f32 D = 0;
        f32 AbsA = 0;
        f32 AbsV = 0;
        if(V != NULL)
        {
            D = getDot(V);
            AbsA = getAbs();
            AbsV = V->getAbs();
            if((AbsA != 0) && (AbsV != 0))
            {
                return acos(D / ( AbsA * AbsV ));
            }
            return 0;
        }
        return 0;
    }

    f32 Vec::getAngleRad(class Vec V)
    {
        f32 D = 0;
        f32 AbsA = 0;
        f32 AbsV = 0;
        D = getDot(&V);
        AbsA = getAbs();
        AbsV = V.getAbs();
        if((AbsA != 0) && (AbsV != 0))
        {
            return acos(D / ( AbsA * AbsV ));
        }
        return 0;
    }

    f32 Vec::getAngleDeg(class Vec V)
    {
        return ( getAngleRad(&V) * ( 180 / Pi(16)));
    }

    f32 Vec::getAngleDeg(class Vec *V)
    {
        if(V != NULL)
        {
            return ( getAngleRad(V) * ( 180 / Pi(16)));
        }
        return 0;
    }

    Vec Vec::getProjected(class Vec *V)
    {
        f32 D = 0;
        f32 B2 = 0;
        f32 x,y,z;
        if(V != NULL)
        {
            D  = getDot(V);
            x  = V->getX();
            y  = V->getY();
            z  = V->getZ();
            B2 = x*x + y*y + z*z;
            if(B2 != 0)
            {
                D  = D / B2;
                return Vec("PROJ",D*x, D*y, D*z);
            }
            return Vec("FAIL",0,0,0);
        }
        return Vec("FAIL",0,0,0);
    }


    Vec Vec::getOrtogonal(class Vec *V)
    {
        return Vec(0,0,0);
    }

    Vec Vec::getCross(class Vec *V)
    {
        if(V != NULL)
        {
            return Vec("CROSS",
                       (getY() * V->getZ()) - (getZ() * V->getY()),
                       (getZ() * V->getX()) - (getX() * V->getZ()),
                       (getX() * V->getY()) - (getY() * V->getX()));
        }
        return Vec("FAIL");
    }

    Vec Vec::getCross(class Vec V)
    {
            f32 x,y,z;
            x = getX();
            y = getY();
            z = getZ();
            return Vec("CROSS",
                       (y * V.getZ()) - (z * V.getY()),
                       (z * V.getX()) - (x * V.getZ()),
                       (x * V.getY()) - (y * V.getX()));
    }

    Vec& Vec::Cross(class Vec *V)
    {
        if(V != NULL)
        {
            f32 x,y,z;
            x = getX();
            y = getY();
            z = getZ();
            Set((y * V->getZ()) - (z * V->getY()),
                (z * V->getX()) - (x * V->getZ()),
                (x * V->getY()) - (y * V->getX()));
        }
        return *this;
    }

    Vec& Vec::Cross(class Vec V)
    {
        f32 x,y,z;
        x = getX();
        y = getY();
        z = getZ();
        Set((y * V.getZ()) - (z * V.getY()),
            (z * V.getX()) - (x * V.getZ()),
            (x * V.getY()) - (y * V.getX()));
        return *this;
    }


    f32 Vec::getDot(class Vec *V)
    {
        if(V != NULL)
        {
            return (getX()*V->getX() +
                    getY()*V->getY() +
                    getZ()*V->getZ());
        }
        return 0;
    }

    f32 Vec::getDot(class Vec V)
    {
        return (getX()*V.getX() +
                getY()*V.getY() +
                getZ()*V.getZ());
    }

    Vec& Vec::Add(class Vec *V)
    {
        if(V != NULL)
        {
            setX(getX() + V->getX());
            setY(getY() + V->getY());
            setZ(getZ() + V->getZ());
        }
        return *this;
    }

    Vec& Vec::Add(class Vec V)
    {
        setX(getX() + V.getX());
        setY(getY() + V.getY());
        setZ(getZ() + V.getZ());
        return *this;
    }

    Vec Vec::getAdd(class Vec *V)
    {
        if(V != NULL)
        {
            f32 x, y, z;
            x = getX() + V->getX();
            y = getY() + V->getY();
            z = getZ() + V->getZ();
            return Vec("ADD", x, y, z);
        }
        return Vec("FAIL");
    }

    Vec Vec::getAdd(class Vec V)
    {
        f32 x, y, z;
        x = getX() + V.getX();
        y = getY() + V.getY();
        z = getZ() + V.getZ();
        return Vec("ADD", x, y, z);
    }

    Vec& Vec::Sub(class Vec *V)
    {
        if(V != NULL)
        {
            setX(getX() - V->getX());
            setY(getY() - V->getY());
            setZ(getZ() - V->getZ());
        }
        return *this;
    }

    Vec& Vec::Sub(class Vec V)
    {
        setX(getX() - V.getX());
        setY(getY() - V.getY());
        setZ(getZ() - V.getZ());
        return *this;
    }

    Vec Vec::getSub(class Vec *V)
    {
        if(V != NULL)
        {
            f32 x, y, z;
            x = getX() - V->getX();
            y = getY() - V->getY();
            z = getZ() - V->getZ();
            return Vec("SUB", x, y, z);
        }
        return Vec("FAIL");
    }

    Vec Vec::getSub(class Vec V)
    {
        f32 x, y, z;
        x = getX() - V.getX();
        y = getY() - V.getY();
        z = getZ() - V.getZ();
        return Vec("SUB", x, y, z);

    }

    Vec& Vec::Set(class Vec *V)
    {
        if(V != NULL)
        {
            setX(V->getX());
            setY(V->getY());
            setZ(V->getZ());
        }
        return *this;
    }

    Vec& Vec::Set(class Vec V)
    {
        setX(V.getX());
        setY(V.getY());
        setZ(V.getZ());
        return *this;
    }

    Vec& Vec::Set(f32 x, f32 y, f32 z)
    {
        setX(x);
        setY(y);
        setZ(z);
        return *this;
    }

    Vec& Vec::Set(f32 x, f32 y)
    {
        setX(x);
        setY(y);
        setZ(0);
        return *this;
    }

    Vec& Vec::Set(f32 x)
    {
        setX(x);
        setY(0);
        setZ(0);
        return *this;
    }

    f32 Vec::getDirCos(u8 Axis)
    {
        f32 AbsA = getAbs();
        if(AbsA != 0)
        {
            if(Axis == 'x') return getX() / AbsA;
            if(Axis == 'y') return getY() / AbsA;
            if(Axis == 'z') return getZ() / AbsA;
        }
        return 0;
    }

    Vec& Vec::Mul(f32 Num)
    {
        setX(getX() * Num);
        setY(getY() * Num);
        setZ(getZ() * Num);
        return *this;
    }

    Vec Vec::getMul(f32 Num)
    {
        return Vec("MUL",getX() * Num,
                         getY() * Num,
                         getZ() * Num);
    }

    Vec& Vec::Div(f32 Num)
    {
        if(Num != 0)
        {
            setX(getX() / Num);
            setY(getY() / Num);
            setZ(getZ() / Num);
        }
        return *this;
    }

    Vec Vec::getDiv(f32 Num)
    {
        if(Num != 0)
        {
            return Vec("DIV",getX() / Num,
                             getY() / Num,
                             getZ() / Num);
        }
        return Vec("FAIL");
    }

    Vec& Vec::Offset(class Vec *Dir, f32 Num)
    {
        cVec D;
        if(Dir != NULL)
        {
            D = Dir->getNormalized();
            D.Mul(Num);
            setX(getX() + D.getX());
            setY(getY() + D.getY());
            setZ(getZ() + D.getZ());
        }
        return *this;
    }

    Vec& Vec::Offset(class Vec Dir, f32 Num)
    {
        cVec D;
             D = Dir.getNormalized();
             D.Mul(Num);
        setX(getX() + D.getX());
        setY(getY() + D.getY());
        setZ(getZ() + D.getZ());
        return *this;
    }

    Vec Vec::getOffset(class Vec *Dir, f32 Num)
    {
        if(Dir != NULL)
        {
            cVec D;
                 D = Dir->getNormalized();
                 D.Mul(Num);
            return Vec((getX() + D.getX()),
                       (getY() + D.getY()),
                       (getZ() + D.getZ()));
        }
        return Vec("FAIL");
    }

    Vec Vec::getOffset(class Vec Dir, f32 Num)
    {
        cVec D;
             D = Dir.getNormalized();
             D.Mul(Num);
        return Vec((getX() + D.getX()),
                   (getY() + D.getY()),
                   (getZ() + D.getZ()));
    }

    Vec& Vec::Neg(void)
    {
        setX(-getX());
        setY(-getY());
        setZ(-getZ());
        return *this;
    }

    Vec Vec::getNeg(void)
    {
        return Vec("NEG",-getX(),-getY(),-getZ());
    }

    Vec& Vec::RollL(void)
    {  // X Y Z  ->  Z X Y
        f32 T;
        T = Z;
        Z = Y;
        Y = X;
        X = T;
        return *this;
    }

    Vec Vec::getRollL(void)
    {  // X Y Z  ->  Z X Y
        return Vec(Z,X,Y);
    }

    Vec& Vec::RollR(void)
    {  // X Y Z  ->  Y Z X
        f32 T;
        T = X;
        X = Y;
        Y = Z;
        Z = T;
        return *this;
    }

    Vec Vec::getRollR(void)
    {  // X Y Z  ->  Y Z X
        return Vec(Y,Z,X);
    }

    Vec& Vec::Swap(const char* Comp)
    {
        u32 Len  = StrCppOverallLen((u8*)Comp);
        f32 T    = 0;
        if(Len == 3)
        {
            if(!StrCppStartsLike(Comp,"xy") || !StrCppStartsLike(Comp,"yx"))
            {
                T = X;
                X = Y;
                Y = T;
            }
            if(!StrCppStartsLike(Comp,"yz") || !StrCppStartsLike(Comp,"zy"))
            {
                T = Y;
                Y = Z;
                Z = T;
            }
            if(!StrCppStartsLike(Comp,"zx") || !StrCppStartsLike(Comp,"xz"))
            {
                T = Y;
                Y = Z;
                Z = T;
            }
        }
        return *this;
    }

    Vec Vec::getSwap(const char* Comp)
    {
        u32 Len  = StrCppOverallLen((u8*)Comp);
        if(Len == 3)
        {
            if(!StrCppStartsLike(Comp,"xy") || !StrCppStartsLike(Comp,"yx"))
            {
                return Vec("SWZX",getY(),getX(),getZ());
            }
            if(!StrCppStartsLike(Comp,"yz") || !StrCppStartsLike(Comp,"zy"))
            {
                return Vec("SWYZ",getX(),getZ(),getY());
            }
            if(!StrCppStartsLike(Comp,"zx") || !StrCppStartsLike(Comp,"xz"))
            {
                return Vec("SWZX",getZ(),getY(),getX());
            }
        }
        return Vec("FAIL");
    }
#endif
