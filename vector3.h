#ifndef __VECTOR3__H_
    #define __VECTOR3__H_
    #define TSP_PI 3.1415927410125732
    typedef class Vec
    {
        private:
            u32 Key;
            f32 X;
            f32 Y;
            f32 Z;
            u8 *Name;
            class Vec *Next;
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
            u8          isCollinear (class Vec *V);
            u8          isCollinear (class Vec &V);
            u8          isOrthogonal(class Vec *V);
            u8          isOrthogonal(class Vec &V);
            u8          isCoplanar  (class Vec &A, class Vec &B);
            u8          isCoplanar  (class Vec *A, class Vec *B);
            u8          isCoplanar  (class Vec *A, class Vec &B);
            u8          isCoplanar  (class Vec &A, class Vec *B);
            f32         getDistance (class Vec *V);
            f32         getDistance (class Vec &V);
            f32         getDistance (void);
            Vec&           Direction(class Vec *V);
            Vec&           Direction(class Vec &V);
            Vec&           Direction(void);
            class Vec   getDirection(class Vec *V);
            class Vec   getDirection(class Vec &V);
            class Vec   getDirection(void);
            f32         getX(){ return X; };
            f32         getY(){ return Y; };
            f32         getZ(){ return Z; };
            u32         getKey(){ return Key; };
            u8         *getName(){ return Name; };
            class Vec  *getNext(){ return Next; };
            Vec&        setX(f32 x){ X = x; return *this; };
            Vec&        setY(f32 y){ Y = y; return *this; };
            Vec&        setZ(f32 z){ Z = z; return *this; };
            Vec&        setKey(u32 k){ Key = k; return *this; };
            Vec&        setName(const char *pcName){ Name = (u8*)pcName; return *this; };
            Vec&        setNext(class  Vec *pvNext){ Next = pvNext;      return *this; };
            f32         getAngleDeg(class  Vec *V);
            f32         getAngleDeg(class  Vec &V);
            f32         getAngleRad(class  Vec *V);
            f32         getAngleRad(class  Vec &V);
            Vec&           Project(class Vec *V);
            Vec&           Project(class Vec &V);
            class Vec   getProject(class Vec *V);
            class Vec   getProject(class Vec &V);
            Vec&           Add(class Vec *V);
            Vec&           Add(class Vec &V);
            class Vec   getAdd(class Vec *V);
            class Vec   getAdd(class Vec &V);
            Vec&           Sub(class Vec *V);
            Vec&           Sub(class Vec &V);
            class Vec   getSub(class Vec *V);
            class Vec   getSub(class Vec &V);
            f32         getCosine(u8);
            Vec&           Neg(void);
            class Vec   getNeg(void);
            Vec&           Mul(f32 Num);
            class Vec   getMul(f32 Num);
            Vec&           Div(f32 Num);
            class Vec   getDiv(f32 Num);
            f32         getMix(class Vec &A, class Vec &B);
            f32         getMix(class Vec *A, class Vec *B);
            f32         getMix(class Vec *A, class Vec &B);
            f32         getMix(class Vec &A, class Vec *B);
            Vec&           Set(class Vec &V);
            Vec&           Set(class Vec *V);
            Vec&           Set(f32 x, f32 y, f32 z);
            Vec&           Set(f32 x, f32 y);
            Vec&           Set(f32 x);
            Vec&           Offset(class Vec &Dir, f32 Num);
            Vec&           Offset(class Vec *Dir, f32 Num);
            class Vec   getOffset(class Vec &Dir, f32 Num);
            class Vec   getOffset(class Vec *Dir, f32 Num);
            Vec&           Cross(class Vec *V);
            Vec&           Cross(class Vec &V);
            class Vec   getCross(class Vec *V);
            class Vec   getCross(class Vec &V);
            f32         getDot(class Vec *V);
            f32         getDot(class Vec &V);
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
         this,getNext(),getName(),getKey(),getX(),getY(),getZ());
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
      setX(x);
      setY(y);
      setZ(z);
      setKey(k);
      setName(N);
      setNext(Next);
    }

    Vec::Vec(const char *N, f32 x, f32 y, f32 z, class Vec *Next)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(N);
      setNext(Next);
    }
    Vec::Vec(const char *N)
    {
      setX(0.0);
      setY(0.0);
      setZ(0.0);
      setKey(0);
      setName(N);
      setNext(NULL);
    }

    Vec::Vec(const char *N, f32 x, f32 y, f32 z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(N);
      setNext(NULL);
    }

    Vec::Vec(f32 x, f32 y, f32 z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName("XYZ");
      setNext(NULL);
    }

    Vec::Vec(f32 x, f32 y)
    {
      setX(x);
      setY(y);
      setZ(0.0);
      setKey(0);
      setName("XY");
      setNext(NULL);
    }

    Vec::Vec(f32 x)
    {
      setX(x);
      setY(0.0);
      setZ(0.0);
      setKey(0);
      setName("X");
      setNext(NULL);
    }

    Vec::Vec()
    {
      setX(0.0);
      setY(0.0);
      setZ(0.0);
      setKey(0);
      setName(NULL);
      setNext(NULL);
    }

    Vec::~Vec()
    {
      free(getName());
    }

    u8 Vec::isOrthogonal(class Vec *V)
    {
      if(V != NULL)
      {
        if(getDot(V) == 0){ return 0xFF; }
      }
      return 0x00;
    }

    u8 Vec::isOrthogonal(class Vec &V)
    {
      if(getDot(V) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCollinear(class Vec *V)
    {
      f32 X, Y, Z;
      if(V != NULL)
      {
        X = getX() / V->getX();
        Y = getY() / V->getY();
        Z = getZ() / V->getZ();
        if(X == Y && Y == Z && Z == X){ return 0xFF; }
      }
      return 0x00;
    }

    u8 Vec::isCollinear(class Vec &V)
    {
      f32 X = getX() / V.getX();
      f32 Y = getY() / V.getY();
      f32 Z = getZ() / V.getZ();
      if(X == Y && Y == Z && Z == X){ return 0xFF; }
      return 0x00;
    }

    f32 Vec::getDistance(class Vec *V)
    {
      if(V != NULL)
      {
        return sqrt((getX() - V->getX()) * (getX() - V->getX()) +
                    (getY() - V->getY()) * (getY() - V->getY()) +
                    (getZ() - V->getZ()) * (getZ() - V->getZ()));
      }else{
        return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
      }
    }

    f32 Vec::getDistance(class Vec &V)
    {
      return sqrt((getX() - V.getX()) * (getX() - V.getX()) +
                  (getY() - V.getY()) * (getY() - V.getY()) +
                  (getZ() - V.getZ()) * (getZ() - V.getZ()));
    }

    f32 Vec::getDistance(void)
    {
      return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
    }

    Vec Vec::getDirection(class Vec *V)
    {
      f32 D;
      if(V != NULL)
      {
        D = getDistance(V);
        if(D != 0)
        {
          return Vec("DIRORG",(getX() - V->getX()) / D,
                              (getY() - V->getY()) / D,
                              (getZ() - V->getZ()) / D);
        }
        return Vec("FAIL",0.0,0.0,0.0);
      }else{
        D = getDistance();
        if(D != 0)
        {
          return Vec("DIRORG",getX() / D,
                              getY() / D,
                              getZ() / D);
        }
        return Vec("FAIL",0.0,0.0,0.0);
      }
    }

    Vec Vec::getDirection(class Vec &V)
    {
      f32 D = getDistance(&V);
      if(D != 0)
      {
        return Vec("DIRORG",(getX() - V.getX()) / D,
                            (getY() - V.getY()) / D,
                            (getZ() - V.getZ()) / D);
      }
      return Vec("FAIL",0.0,0.0,0.0);
    }

    Vec Vec::getDirection(void)
    {
      f32 D = getDistance();
      if(D != 0)
      {
        return Vec("DIRORG",getX() / D,
                            getY() / D,
                            getZ() / D);
      }
      return Vec("FAIL",0.0,0.0,0.0);
    }

    Vec& Vec::Direction(class Vec *V)
    {
      f32 D;
      if(V != NULL)
      {
        D = getDistance(V);
        if(D != 0)
        {
          setX((getX() - V->getX()) / D);
          setY((getY() - V->getY()) / D);
          setZ((getZ() - V->getZ()) / D);
        }
      }else{
        D = getDistance();
        if(D != 0)
        {
          setX(getX() / D);
          setY(getY() / D);
          setZ(getZ() / D);
        }
      }
      return *this;
    }

    Vec& Vec::Direction(class Vec &V)
    {
      f32 D = getDistance(&V);
      if(D != 0)
      {
        setX((getX() - V.getX()) / D);
        setY((getY() - V.getY()) / D);
        setZ((getZ() - V.getZ()) / D);
      }
      return *this;
    }

    Vec& Vec::Direction(void)
    {
      f32 D = getDistance();
      if(D != 0)
      {
        setX(getX() / D);
        setY(getY() / D);
        setZ(getZ() / D);
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
      a.Cross(&b);
    }

    void operator*=(Vec &a, Vec b)
    {
      a.Mul(a.getDot(&b));
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
      return Vec("FAIL",0.0,0.0,0.0);
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
      if(a.getDistance() >= b.getDistance())
        return 0xFF;
      return 0x00;
    }

    u8 operator<=(Vec a, Vec b)
    {
      if(a.getDistance() <= b.getDistance())
        return 0xFF;
      return 0x00;
    }

    u8 operator>(Vec a, Vec b)
    {
      if(a.getDistance() > b.getDistance())
        return 0xFF;
      return 0x00;
    }

    u8 operator<(Vec a, Vec b)
    {
      if(a.getDistance() < b.getDistance())
        return 0xFF;
      return 0x00;
    }

    void operator++(Vec &v, s32 a)
    {
      cVec Dr = v.getDirection(NULL);
      v.setX(v.getX() + Dr.getX());
      v.setY(v.getY() + Dr.getY());
      v.setZ(v.getZ() + Dr.getZ());
    }

    void operator--(Vec &v, s32 a)
    {
      cVec Dr = v.getDirection(NULL);
      v.setX(v.getX() - Dr.getX());
      v.setY(v.getY() - Dr.getY());
      v.setZ(v.getZ() - Dr.getZ());
    }

    void operator++(Vec &v)
    {
      cVec Dr = v.getDirection(NULL);
      v.setX(v.getX() + Dr.getX());
      v.setY(v.getY() + Dr.getY());
      v.setZ(v.getZ() + Dr.getZ());
    }

    void operator--(Vec &v)
    {
      cVec Dr = v.getDirection(NULL);
      v.setX(v.getX() - Dr.getX());
      v.setY(v.getY() - Dr.getY());
      v.setZ(v.getZ() - Dr.getZ());
    }

    f32 Vec::getAngleRad(class Vec *V)
    {
      f32 Dot, AbsA, AbsB;
      if(V != NULL)
      {
        Dot = getDot(V);
        AbsA = getDistance();
        AbsB = V->getDistance();
        if((AbsA != 0) && (AbsB != 0))
        {
          return acos(Dot / ( AbsA * AbsB ));
        }
        return 0;
      }
      return 0;
    }

    f32 Vec::getAngleRad(class Vec &V)
    {
      f32 Dot  = getDot(&V);
      f32 AbsA = getDistance();
      f32 AbsB = V.getDistance();
      if((AbsA != 0) && (AbsB != 0))
      {
        return acos(Dot / ( AbsA * AbsB ));
      }
      return 0;
    }

    f32 Vec::getAngleDeg(class Vec &V)
    {
      return ( getAngleRad(&V) * ( 180 / TSP_PI));
    }

    f32 Vec::getAngleDeg(class Vec *V)
    {
      if(V != NULL)
      {
        return ( getAngleRad(V) * ( 180 / TSP_PI));
      }
      return 0;
    }

    Vec& Vec::Project(class Vec *V)
    {
      f32 Dotp, Dst2;
      f32 CpyX, CpyY, CpyZ;
      if(V != NULL)
      {
        CpyX = V->getX();
        CpyY = V->getY();
        CpyZ = V->getZ();
        Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
        if(Dst2 != 0)
        {
          Dotp  = getDot(V) / Dst2;
          setName("PROJ");
          Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
          return *this;
        }
        return *this;
      }
      return *this;
    }

    Vec& Vec::Project(class Vec &V)
    {
      f32 Dotp, Dst2;
      f32 CpyX = V.getX();
      f32 CpyY = V.getY();
      f32 CpyZ = V.getZ();
      Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 != 0)
      {
        Dotp  = getDot(V) / Dst2;
        setName("PROJ");
        Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      }
      return*this;
    }

    Vec Vec::getProject(class Vec *V)
    {
      f32 Dotp, Dst2;
      f32 CpyX, CpyY, CpyZ;
      if(V != NULL)
      {
        CpyX = V->getX();
        CpyY = V->getY();
        CpyZ = V->getZ();
        Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
        if(Dst2 != 0)
        {
          Dotp  = getDot(V) / Dst2;
          return Vec("PROJ",Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
        }
        return Vec("FAIL",0.0,0.0,0.0);
      }
      return Vec("FAIL",0.0,0.0,0.0);
    }

    Vec Vec::getProject(class Vec &V)
    {
      f32 Dotp, Dst2;
      f32 CpyX = V.getX();
      f32 CpyY = V.getY();
      f32 CpyZ = V.getZ();
      Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 != 0)
      {
        Dotp  = getDot(V) / Dst2;
        return Vec("PROJ",Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      }
      return Vec("FAIL",0.0,0.0,0.0);
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

    Vec Vec::getCross(class Vec &V)
    {
      return Vec("CROSS",
                 (getY() * V.getZ()) - (getZ() * V.getY()),
                 (getZ() * V.getX()) - (getX() * V.getZ()),
                 (getX() * V.getY()) - (getY() * V.getX()));
    }

    Vec& Vec::Cross(class Vec *V)
    {
      if(V != NULL)
      {
        Set((getY() * V->getZ()) - (getZ() * V->getY()),
            (getZ() * V->getX()) - (getX() * V->getZ()),
            (getX() * V->getY()) - (getY() * V->getX()));
      }
      return *this;
    }

    Vec& Vec::Cross(class Vec &V)
    {
      Set((getY() * V.getZ()) - (getZ() * V.getY()),
          (getZ() * V.getX()) - (getX() * V.getZ()),
          (getX() * V.getY()) - (getY() * V.getX()));
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

    f32 Vec::getDot(class Vec &V)
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

    Vec& Vec::Add(class Vec &V)
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

    Vec Vec::getAdd(class Vec &V)
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

    Vec& Vec::Sub(class Vec &V)
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

    Vec Vec::getSub(class Vec &V)
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

    Vec& Vec::Set(class Vec &V)
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

    f32 Vec::getCosine(u8 Axis)
    {
      f32 AbsA = getDistance();
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

    f32 Vec::getMix(class Vec &A, class Vec &B)
    {
      cVec T = A.getCross(B);
      return getDot(T);
    }

    f32 Vec::getMix(class Vec *A, class Vec *B)
    {
      if(A != NULL && B != NULL)
      {
        cVec T = A->getCross(B);
        return getDot(T);
      }
      return 0.0;
    }

    f32 Vec::getMix(class Vec *A, class Vec &B)
    {
      if(A != NULL)
      {
        cVec T = A->getCross(B);
        return getDot(T);
      }
      return 0.0;
    }

    f32 Vec::getMix(class Vec &A, class Vec *B)
    {
      if(B != NULL)
      {
        cVec T = A.getCross(B);
        return getDot(T);
      }
      return 0.0;
    }

    u8 Vec::isCoplanar(class Vec &A, class Vec &B)
    {
      if(getMix(A,B) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCoplanar(class Vec *A, class Vec *B)
    {
      if(getMix(A,B) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCoplanar(class Vec &A, class Vec *B)
    {
      if(getMix(A,B) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCoplanar(class Vec *A, class Vec &B)
    {
      if(getMix(A,B) == 0){ return 0xFF; }
      return 0x00;
    }

    Vec& Vec::Offset(class Vec *Dir, f32 Num)
    {
      cVec D;
      if(Dir != NULL)
      {
        D = Dir->getDirection();
        D.Mul(Num);
        setX(getX() + D.getX());
        setY(getY() + D.getY());
        setZ(getZ() + D.getZ());
      }
      return *this;
    }

    Vec& Vec::Offset(class Vec &Dir, f32 Num)
    {
      cVec D = Dir.getDirection();
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
        cVec D = Dir->getDirection();
             D.Mul(Num);
        return Vec((getX() + D.getX()),
                   (getY() + D.getY()),
                   (getZ() + D.getZ()));
      }
      return Vec("FAIL");
    }

    Vec Vec::getOffset(class Vec &Dir, f32 Num)
    {
      cVec D = Dir.getDirection();
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
      f32 T = 0;
      u8  arswap[3] = {0};
      u32 len = strlen(Comp);
      if(len == 2)
      {
        arswap[0] = Comp[0] | 0x20;
        arswap[1] = Comp[1] | 0x20;
        if(!memcmp(arswap,"xy",2) || !memcmp(arswap,"yx",2))
        {
          T = X; X = Y; Y = T;
        }
        if(!memcmp(arswap,"yz",2) || !memcmp(arswap,"zy",2))
        {
          T = Y; Y = Z; Z = T;
        }
        if(!memcmp(arswap,"zx",2) || !memcmp(arswap,"xz",2))
        {
          T = Y; Y = Z; Z = T;
        }
      }
      return *this;
    }

    Vec Vec::getSwap(const char* Comp)
    {
      u8  arswap[3] = {0};
      u32 len = strlen(Comp);
      if(len >= 2)
      {
        arswap[0] = Comp[0] | 0x20;
        arswap[1] = Comp[1] | 0x20;
        if(!memcmp(arswap,"xy",2) || !memcmp(arswap,"yx",2))
        {
          return Vec("SWXY",getY(),getX(),getZ());
        }
        if(!memcmp(arswap,"yz",2) || !memcmp(arswap,"zy",2))
        {
            return Vec("SWYZ",getX(),getZ(),getY());
        }
        if(!memcmp(arswap,"zx",2) || !memcmp(arswap,"xz",2))
        {
          return Vec("SWZX",getZ(),getY(),getX());
        }
      }
      return Vec("FAIL");
    }
#endif
