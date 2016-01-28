#ifndef __TSP_VECTOR__H_
    #define __TSP_VECTOR__H_
    #define TSP_PI 3.141592653589793238462643383279502884197169399375105820974944
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
            friend void operator+=(Vec&, f32);
            friend void operator+=(Vec&, Vec);
            friend void operator-=(Vec&, f32);
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
            u8          isCollinear (class Vec *v);
            u8          isCollinear (class Vec &v);
            u8          isOrthogonal(class Vec *v);
            u8          isOrthogonal(class Vec &v);
            u8          isCoplanar  (class Vec &a, class Vec &b);
            u8          isCoplanar  (class Vec *a, class Vec *b);
            u8          isCoplanar  (class Vec *a, class Vec &b);
            u8          isCoplanar  (class Vec &a, class Vec *b);
            f32         getDistance (class Vec *v);
            f32         getDistance (class Vec &v);
            f32         getDistance (void);
            Vec&           Direction(class Vec *v);
            Vec&           Direction(class Vec &v);
            Vec&           Direction(void);
            class Vec   getDirection(class Vec *v);
            class Vec   getDirection(class Vec &v);
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
            f32         getAngleDeg(class  Vec *v);
            f32         getAngleDeg(class  Vec &v);
            f32         getAngleRad(class  Vec *v);
            f32         getAngleRad(class  Vec &v);
            f32         getAreaTriangle(class Vec *v);
            f32         getAreaTriangle(class Vec &v);
            f32         getAreaParallelogram(class Vec *v);
            f32         getAreaParallelogram(class Vec &v);
            f32         getVolumeTetrahedron(class Vec &a, class Vec &b);
            f32         getVolumeTetrahedron(class Vec *a, class Vec *b);
            f32         getVolumeTetrahedron(class Vec *a, class Vec &b);
            f32         getVolumeTetrahedron(class Vec &a, class Vec *b);
            Vec&           Project(class Vec *v);
            Vec&           Project(class Vec &v);
            class Vec   getProject(class Vec *v);
            class Vec   getProject(class Vec &v);
            Vec&           Add(class Vec *v);
            Vec&           Add(class Vec &v);
            class Vec   getAdd(class Vec *v);
            class Vec   getAdd(class Vec &v);
            Vec&           Sub(class Vec *v);
            Vec&           Sub(class Vec &v);
            class Vec   getSub(class Vec *v);
            class Vec   getSub(class Vec &v);
            f32         getCosine(u8);
            Vec&           Neg(void);
            class Vec   getNeg(void);
            Vec&           Mul(f32 n);
            class Vec   getMul(f32 n);
            Vec&           Div(f32 n);
            class Vec   getDiv(f32 n);
            f32         getMix(class Vec &a, class Vec &b);
            f32         getMix(class Vec *a, class Vec *b);
            f32         getMix(class Vec *a, class Vec &b);
            f32         getMix(class Vec &a, class Vec *b);
            Vec&           Set(class Vec &v);
            Vec&           Set(class Vec *v);
            Vec&           Set(f32 x, f32 y, f32 z);
            Vec&           Set(f32 x, f32 y);
            Vec&           Set(f32 x);
            Vec&           Offset(class Vec &Dir, f32 n);
            Vec&           Offset(class Vec *Dir, f32 n);
            class Vec   getOffset(class Vec &Dir, f32 n);
            class Vec   getOffset(class Vec *Dir, f32 n);
            Vec&           Cross(class Vec *v);
            Vec&           Cross(class Vec &v);
            class Vec   getCross(class Vec *v);
            class Vec   getCross(class Vec &v);
            f32         getDot(class Vec *v);
            f32         getDot(class Vec &v);
            Vec&           RollR(void);
            class Vec   getRollR(void);
            Vec&           RollL(void);
            class Vec   getRollL(void);
            Vec&           Swap(const char* Comp);
            class Vec   getSwap(const char* Comp);
            Vec&           Print(void);
            Vec&           PrintTrajectory(void);
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

    Vec& Vec::Print(void)
    {
      printf("\n\rVec %p > %p --> %s, %u\n\rXYZ = { %10.4f, %10.4f, %10.4f }\n\r",
         this,getNext(),getName(),getKey(),getX(),getY(),getZ());
      return *this;
    }

    Vec& Vec::PrintTrajectory(void)
    {
      cVec *v = this;
      while(v != NULL)
      {
        v->Print();
        v = v->getNext();
      }
      return *this;
    }

    Vec::Vec(const char *Name, f32 x, f32 y, f32 z, u32 k, class Vec *Next)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(k);
      setName(Name);
      setNext(Next);
    }

    Vec::Vec(const char *Name, f32 x, f32 y, f32 z, class Vec *Next)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(Name);
      setNext(Next);
    }
    Vec::Vec(const char *Name)
    {
      setX(0.0);
      setY(0.0);
      setZ(0.0);
      setKey(0);
      setName(Name);
      setNext(NULL);
    }

    Vec::Vec(const char *Name, f32 x, f32 y, f32 z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(Name);
      setNext(NULL);
    }

    Vec::Vec(f32 x, f32 y, f32 z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec(f32 x, f32 y)
    {
      setX(x);
      setY(y);
      setZ(0.0);
      setKey(0);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec(f32 x)
    {
      setX(x);
      setY(0.0);
      setZ(0.0);
      setKey(0);
      setName(NULL);
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

    u8 Vec::isOrthogonal(class Vec *v)
    {
      if(v == NULL){ return 0x00; }
      if(getDot(v) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isOrthogonal(class Vec &v)
    {
      if(getDot(v) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCollinear(class Vec *v)
    {
      if(v == NULL){ return 0x00; }
      f32 x = getX() / v->getX();
      f32 y = getY() / v->getY();
      f32 z = getZ() / v->getZ();
      if(x == y && y == z && z == x){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCollinear(class Vec &v)
    {
      f32 x = getX() / v.getX();
      f32 y = getY() / v.getY();
      f32 z = getZ() / v.getZ();
      if(x == y && y == z && z == x){ return 0xFF; }
      return 0x00;
    }

    f32 Vec::getDistance(void)
    {
      return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
    }

    f32 Vec::getDistance(class Vec *v)
    {
      if(v == NULL){ return getDistance(); }
      return sqrt((getX() - v->getX()) * (getX() - v->getX()) +
                  (getY() - v->getY()) * (getY() - v->getY()) +
                  (getZ() - v->getZ()) * (getZ() - v->getZ()));
    }

    f32 Vec::getDistance(class Vec &v)
    {
      return sqrt((getX() - v.getX()) * (getX() - v.getX()) +
                  (getY() - v.getY()) * (getY() - v.getY()) +
                  (getZ() - v.getZ()) * (getZ() - v.getZ()));
    }

    Vec Vec::getDirection(void)
    {
      f32 D = getDistance();
      if(D == 0){ return Vec("FAIL"); }
      return Vec(getX() / D, getY() / D, getZ() / D);
    }

    Vec Vec::getDirection(class Vec *v)
    {
      if(v == NULL){ return getDirection(); }
      f32 D = getDistance(v);
      if(D == 0){ return Vec("FAIL"); }
      return Vec((getX() - v->getX()) / D, (getY() - v->getY()) / D, (getZ() - v->getZ()) / D);
    }

    Vec Vec::getDirection(class Vec &v)
    {
      f32 D = getDistance(&v);
      if(D == 0){ return Vec("FAIL"); }
      return Vec((getX() - v.getX()) / D, (getY() - v.getY()) / D, (getZ() - v.getZ()) / D);
    }

    Vec& Vec::Direction(void)
    {
      f32 D = getDistance();
      if(D == 0){ return *this; }
      setX(getX() / D);
      setY(getY() / D);
      setZ(getZ() / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec *v)
    {
      if(v == NULL){ return Direction(); }
      f32 D = getDistance(v);
      if(D == 0){ return *this; }
      setX((getX() - v->getX()) / D);
      setY((getY() - v->getY()) / D);
      setZ((getZ() - v->getZ()) / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec &v)
    {
      f32 D = getDistance(&v);
      if(D == 0){ return *this; }
      setX((getX() - v.getX()) / D);
      setY((getY() - v.getY()) / D);
      setZ((getZ() - v.getZ()) / D);
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
      return  Vec(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
    }

    Vec operator-(Vec a, Vec b)
    {
      return  Vec(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
    }

    void operator+=(Vec &a, f32 b)
    {
      a.setX(a.getX() + b);
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

    void operator-=(Vec &a, f32 b)
    {
      a.setX(a.getX() - b);
    }

    void operator-=(Vec &a, Vec b)
    {
      a.setX(a.getX() - b.getX());
      a.setY(a.getY() - b.getY());
      a.setZ(a.getZ() - b.getZ());
    }

    Vec operator*(f32 a, Vec b)
    {
      return Vec(a * b.getX(), a * b.getY(), a * b.getZ());
    }

    Vec operator*(Vec b, f32 a)
    {
      return Vec(a * b.getX(), a * b.getY(), a * b.getZ());
    }

    Vec  operator/(Vec b, f32 a)
    {
      if(a == 0){ return Vec("FAIL"); }
      return Vec(b.getX() / a, b.getY() / a, b.getZ() / a);
    }

    void operator*=(Vec &a, f32 b)
    {
      a.setX(a.getX() * b);
      a.setY(a.getY() * b);
      a.setZ(a.getZ() * b);
    }

    void operator/=(Vec &a, f32 b)
    {
      if(b == 0){ return; }
      a.setX(a.getX() / b);
      a.setY(a.getY() / b);
      a.setZ(a.getZ() / b);
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
      cVec Dr = v.getDirection();
      v.setX(v.getX() + Dr.getX());
      v.setY(v.getY() + Dr.getY());
      v.setZ(v.getZ() + Dr.getZ());
    }

    void operator--(Vec &v, s32 a)
    {
      cVec Dr = v.getDirection();
      v.setX(v.getX() - Dr.getX());
      v.setY(v.getY() - Dr.getY());
      v.setZ(v.getZ() - Dr.getZ());
    }

    void operator++(Vec &v)
    {
      cVec Dr = v.getDirection();
      v.setX(v.getX() + Dr.getX());
      v.setY(v.getY() + Dr.getY());
      v.setZ(v.getZ() + Dr.getZ());
    }

    void operator--(Vec &v)
    {
      cVec Dr = v.getDirection();
      v.setX(v.getX() - Dr.getX());
      v.setY(v.getY() - Dr.getY());
      v.setZ(v.getZ() - Dr.getZ());
    }

    f32 Vec::getAngleRad(class Vec *v)
    {
      if(v == NULL){ return 0; }
      f32 Dot = getDot(v);
      f32 Abs = getDistance();
      f32 Abv = v->getDistance();
      if(Abs == 0 || Abv == 0){ return 0; }
      return acos(Dot / ( Abs * Abv ));
    }

    f32 Vec::getAngleRad(class Vec &v)
    {
      f32 Dot = getDot(&v);
      f32 Abs = getDistance();
      f32 Abv = v.getDistance();
      if(Abs == 0 || Abv == 0){ return 0; }
      return acos(Dot / ( Abs * Abv ));
    }

    f32 Vec::getAngleDeg(class Vec &v)
    {
      return ( getAngleRad(&v) * ( 180 / TSP_PI));
    }

    f32 Vec::getAngleDeg(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return ( getAngleRad(v) * ( 180 / TSP_PI));
    }

    Vec& Vec::Project(class Vec *v)
    {
      if(v == NULL){ return *this; }
      f32 CpyX = v->getX();
      f32 CpyY = v->getY();
      f32 CpyZ = v->getZ();
      f32 Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return *this; }
      f32 Dotp = getDot(v) / Dst2;
      Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      return *this;
    }

    Vec& Vec::Project(class Vec &v)
    {
      f32 CpyX = v.getX();
      f32 CpyY = v.getY();
      f32 CpyZ = v.getZ();
      f32 Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return *this; }
      f32 Dotp = getDot(v) / Dst2;
      Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      return *this;
    }

    Vec Vec::getProject(class Vec *v)
    {
      if(v == NULL){ return Vec("FAIL"); }
      f32 CpyX = v->getX();
      f32 CpyY = v->getY();
      f32 CpyZ = v->getZ();
      f32 Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return Vec("FAIL"); }
      f32 Dotp  = getDot(v) / Dst2;
      return Vec(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
    }

    Vec Vec::getProject(class Vec &v)
    {
      f32 CpyX = v.getX();
      f32 CpyY = v.getY();
      f32 CpyZ = v.getZ();
      f32 Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return Vec("FAIL"); }
      f32 Dotp = getDot(v) / Dst2;
      return Vec(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
    }

    Vec Vec::getCross(class Vec *v)
    {
      if(v == NULL){ return Vec("FAIL"); }
      return Vec((getY() * v->getZ()) - (getZ() * v->getY()),
                 (getZ() * v->getX()) - (getX() * v->getZ()),
                 (getX() * v->getY()) - (getY() * v->getX()));
    }

    Vec Vec::getCross(class Vec &v)
    {
      return Vec((getY() * v.getZ()) - (getZ() * v.getY()),
                 (getZ() * v.getX()) - (getX() * v.getZ()),
                 (getX() * v.getY()) - (getY() * v.getX()));
    }

    Vec& Vec::Cross(class Vec *v)
    {
      if(v == NULL){ return *this; }
      Set((getY() * v->getZ()) - (getZ() * v->getY()),
          (getZ() * v->getX()) - (getX() * v->getZ()),
          (getX() * v->getY()) - (getY() * v->getX()));
      return *this;
    }

    Vec& Vec::Cross(class Vec &v)
    {
      Set((getY() * v.getZ()) - (getZ() * v.getY()),
          (getZ() * v.getX()) - (getX() * v.getZ()),
          (getX() * v.getY()) - (getY() * v.getX()));
      return *this;
    }

    f32 Vec::getDot(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return (getX()*v->getX() +
              getY()*v->getY() +
              getZ()*v->getZ());
    }

    f32 Vec::getDot(class Vec &v)
    {
      return (getX()*v.getX() +
              getY()*v.getY() +
              getZ()*v.getZ());
    }

    Vec& Vec::Add(class Vec *v)
    {
      if(v == NULL){ return *this; }
      setX(getX() + v->getX());
      setY(getY() + v->getY());
      setZ(getZ() + v->getZ());
      return *this;
    }

    Vec& Vec::Add(class Vec &v)
    {
      setX(getX() + v.getX());
      setY(getY() + v.getY());
      setZ(getZ() + v.getZ());
      return *this;
    }

    Vec Vec::getAdd(class Vec *v)
    {
      if(v == NULL){ return Vec("FAIL"); }
      f32 x = getX() + v->getX();
      f32 y = getY() + v->getY();
      f32 z = getZ() + v->getZ();
      return Vec(x, y, z);
    }

    Vec Vec::getAdd(class Vec &v)
    {
      f32 x = getX() + v.getX();
      f32 y = getY() + v.getY();
      f32 z = getZ() + v.getZ();
      return Vec(x, y, z);
    }

    Vec& Vec::Sub(class Vec *v)
    {
      if(v == NULL){ return *this; }
      setX(getX() - v->getX());
      setY(getY() - v->getY());
      setZ(getZ() - v->getZ());
      return *this;
    }

    Vec& Vec::Sub(class Vec &v)
    {
      setX(getX() - v.getX());
      setY(getY() - v.getY());
      setZ(getZ() - v.getZ());
      return *this;
    }

    Vec Vec::getSub(class Vec *v)
    {
      if(v == NULL){ return Vec("FAIL"); }
      f32 x = getX() - v->getX();
      f32 y = getY() - v->getY();
      f32 z = getZ() - v->getZ();
      return Vec(x, y, z);
  }

    Vec Vec::getSub(class Vec &v)
    {
      f32 x = getX() - v.getX();
      f32 y = getY() - v.getY();
      f32 z = getZ() - v.getZ();
      return Vec(x, y, z);
    }

    Vec& Vec::Set(class Vec *v)
    {
      if(v == NULL){ return *this; }
      setX(v->getX());
      setY(v->getY());
      setZ(v->getZ());
      return *this;
    }

    Vec& Vec::Set(class Vec &v)
    {
      setX(v.getX());
      setY(v.getY());
      setZ(v.getZ());
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
      f32 Abs = getDistance();
      if(Abs  ==  0 ){ return 0; }
      if(Axis == 'x'){ return getX() / Abs; }
      if(Axis == 'y'){ return getY() / Abs; }
      if(Axis == 'z'){ return getZ() / Abs; }
      return 0;
    }

    Vec& Vec::Mul(f32 n)
    {
      setX(getX() * n);
      setY(getY() * n);
      setZ(getZ() * n);
      return *this;
    }

    Vec Vec::getMul(f32 n)
    {
      return Vec(getX() * n, getY() * n, getZ() * n);
    }

    Vec& Vec::Div(f32 n)
    {
      if(n == 0){ return *this; }
      setX(getX() / n);
      setY(getY() / n);
      setZ(getZ() / n);
      return *this;
    }

    Vec Vec::getDiv(f32 n)
    {
      if(n == 0){ return Vec("FAIL"); }
      return Vec(getX() / n, getY() / n, getZ() / n);
    }

    f32 Vec::getAreaParallelogram(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return fabs(getCross(v).getDistance());
    }

    f32 Vec::getAreaParallelogram(class Vec &v)
    {
      return fabs(getCross(v).getDistance());
    }

    f32 Vec::getAreaTriangle(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return fabs(0.5 * getAreaParallelogram(v));
    }

    f32 Vec::getAreaTriangle(class Vec &v)
    {
      return fabs(0.5 * getAreaParallelogram(v));
    }

    f32 Vec::getMix(class Vec &a, class Vec &b)
    {
      cVec T = a.getCross(b);
      return getDot(T);
    }

    f32 Vec::getMix(class Vec *a, class Vec *b)
    {
      if(a == NULL || b == NULL){ return 0.0; }
      cVec T = a->getCross(b);
      return getDot(T);
    }

    f32 Vec::getMix(class Vec *a, class Vec &b)
    {
      if(a == NULL){ return 0.0; }
      cVec T = a->getCross(b);
      return getDot(T);
    }

    f32 Vec::getMix(class Vec &a, class Vec *b)
    {
      if(b == NULL){ return 0.0; }
      cVec T = a.getCross(b);
      return getDot(T);
    }

    f32 Vec::getVolumeTetrahedron(class Vec &a, class Vec &b)
    {
      return fabs(getMix(a,b) / 6);
    }

    f32 Vec::getVolumeTetrahedron(class Vec *a, class Vec *b)
    {
      if(a == NULL || b == NULL){ return 0; }
      return fabs(getMix(a,b) / 6);
    }

    f32 Vec::getVolumeTetrahedron(class Vec *a, class Vec &b)
    {
      if(a == NULL){ return 0; }
      return fabs(getMix(a,b) / 6);
    }

    f32 Vec::getVolumeTetrahedron(class Vec &a, class Vec *b)
    {
      if(b == NULL){ return 0; }
      return fabs(getMix(a,b) / 6);
    }

    u8 Vec::isCoplanar(class Vec &a, class Vec &b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCoplanar(class Vec *a, class Vec *b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCoplanar(class Vec &a, class Vec *b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    u8 Vec::isCoplanar(class Vec *a, class Vec &b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    Vec& Vec::Offset(class Vec *Dir, f32 n)
    {
      if(Dir == NULL){ return *this; }
      cVec D = Dir->getDirection();
           D.Mul(n);
      setX(getX() + D.getX());
      setY(getY() + D.getY());
      setZ(getZ() + D.getZ());
      return *this;
    }

    Vec& Vec::Offset(class Vec &Dir, f32 n)
    {
      cVec D = Dir.getDirection();
           D.Mul(n);
      setX(getX() + D.getX());
      setY(getY() + D.getY());
      setZ(getZ() + D.getZ());
      return *this;
    }

    Vec Vec::getOffset(class Vec *Dir, f32 n)
    {
      if(Dir == NULL){ return Vec("FAIL"); }
      cVec D = Dir->getDirection();
           D.Mul(n);
      return Vec((getX() + D.getX()),
                 (getY() + D.getY()),
                 (getZ() + D.getZ()));
    }

    Vec Vec::getOffset(class Vec &Dir, f32 n)
    {
      cVec D = Dir.getDirection();
           D.Mul(n);
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
      return Vec(-getX(),-getY(),-getZ());
    }

    Vec& Vec::RollL(void)
    {  // X Y Z  ->  Z X Y
      f32 T = Z;
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
      f32 T = X;
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
      if(len >= 2)
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
          return Vec(getY(),getX(),getZ());
        }
        if(!memcmp(arswap,"yz",2) || !memcmp(arswap,"zy",2))
        {
            return Vec(getX(),getZ(),getY());
        }
        if(!memcmp(arswap,"zx",2) || !memcmp(arswap,"xz",2))
        {
          return Vec(getZ(),getY(),getX());
        }
      }
      return Vec("FAIL");
    }
#endif
