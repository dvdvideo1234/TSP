#ifndef __TSP_VECTOR__H_
    #define __TSP_VECTOR__H_
    #define TSP_NUM float
    #define TSP_STR unsigned char
    #define TSP_KEY unsigned int
    #define TSP_PI 3.141592653589793238462643383279502884197169399375105820974944
    typedef class Vec
    {
        private:
            TSP_KEY Key;
            TSP_NUM X;
            TSP_NUM Y;
            TSP_NUM Z;
            TSP_STR *Name;
            class Vec *Next;
        public:
            friend Vec     operator+ (Vec&, Vec&);
            friend Vec     operator- (Vec&, Vec&);
            friend void    operator+=(Vec&, TSP_NUM);
            friend void    operator+=(Vec&, Vec&);
            friend void    operator-=(Vec&, TSP_NUM);
            friend void    operator-=(Vec&, Vec&);
            friend Vec     operator^ (Vec&, Vec&);
            friend void    operator^=(Vec&, Vec&);
            friend TSP_NUM operator* (Vec&, Vec&);
            friend Vec     operator* (TSP_NUM , Vec&);
            friend Vec     operator* (Vec&, TSP_NUM);
            friend void    operator*=(Vec&, TSP_NUM);
            friend void    operator*=(Vec&, Vec&);
            friend Vec     operator/ (Vec&, TSP_NUM);
            friend void    operator/=(Vec&, TSP_NUM);
            friend TSP_STR operator==(Vec&, Vec&);
            friend TSP_STR operator!=(Vec&, Vec&);
            friend TSP_STR operator>=(Vec&, Vec&);
            friend TSP_STR operator<=(Vec&, Vec&);
            friend TSP_STR operator> (Vec&, Vec&);
            friend TSP_STR operator< (Vec&, Vec&);
            friend void    operator++(Vec&, s32);
            friend void    operator--(Vec&, s32);
            friend void    operator++(Vec&);
            friend void    operator--(Vec&);
            TSP_STR         isCollinear (class Vec *v);
            TSP_STR         isCollinear (class Vec &v);
            TSP_STR         isOrthogonal(class Vec *v);
            TSP_STR         isOrthogonal(class Vec &v);
            TSP_STR         isCoplanar  (class Vec &a, class Vec &b);
            TSP_STR         isCoplanar  (class Vec *a, class Vec *b);
            TSP_STR         isCoplanar  (class Vec *a, class Vec &b);
            TSP_STR         isCoplanar  (class Vec &a, class Vec *b);
            TSP_NUM        getDistance (class Vec *v);
            TSP_NUM        getDistance (class Vec &v);
            TSP_NUM        getDistance (void);
            Vec&              Direction(class Vec *v);
            Vec&              Direction(class Vec &v);
            Vec&              Direction(void);
            class Vec      getDirection(class Vec *v);
            class Vec      getDirection(class Vec &v);
            class Vec      getDirection(void);
            TSP_NUM        getX(){ return X; };
            TSP_NUM        getY(){ return Y; };
            TSP_NUM        getZ(){ return Z; };
            TSP_KEY        getKey(){ return Key; };
            TSP_STR       *getName(){ return Name; };
            class Vec     *getNext(){ return Next; };
            Vec&           setX(TSP_NUM x){ X = x; return *this; };
            Vec&           setY(TSP_NUM y){ Y = y; return *this; };
            Vec&           setZ(TSP_NUM z){ Z = z; return *this; };
            Vec&           setKey(TSP_KEY k){ Key = k; return *this; };
            Vec&           setName(const char *pcName){ Name = (TSP_STR*)pcName; return *this; };
            Vec&           setNext(class  Vec *pvNext){ Next = pvNext;      return *this; };
            TSP_NUM        getAngleDeg(class  Vec *v);
            TSP_NUM        getAngleDeg(class  Vec &v);
            TSP_NUM        getAngleRad(class  Vec *v);
            TSP_NUM        getAngleRad(class  Vec &v);
            TSP_NUM        getAreaTriangle(class Vec *v);
            TSP_NUM        getAreaTriangle(class Vec &v);
            TSP_NUM        getAreaParallelogram(class Vec *v);
            TSP_NUM        getAreaParallelogram(class Vec &v);
            TSP_NUM        getVolumeTetrahedron(class Vec &a, class Vec &b);
            TSP_NUM        getVolumeTetrahedron(class Vec *a, class Vec *b);
            TSP_NUM        getVolumeTetrahedron(class Vec *a, class Vec &b);
            TSP_NUM        getVolumeTetrahedron(class Vec &a, class Vec *b);
            Vec&              Project(class Vec *v);
            Vec&              Project(class Vec &v);
            class Vec      getProject(class Vec *v);
            class Vec      getProject(class Vec &v);
            Vec&              Add(class Vec *v);
            Vec&              Add(class Vec &v);
            class Vec      getAdd(class Vec *v);
            class Vec      getAdd(class Vec &v);
            Vec&              Sub(class Vec *v);
            Vec&              Sub(class Vec &v);
            class Vec      getSub(class Vec *v);
            class Vec      getSub(class Vec &v);
            TSP_NUM        getCosine(TSP_STR);
            Vec&              Neg(void);
            class Vec      getNeg(void);
            Vec&              Mul(TSP_NUM n);
            class Vec      getMul(TSP_NUM n);
            Vec&              Div(TSP_NUM n);
            class Vec      getDiv(TSP_NUM n);
            TSP_NUM        getMix(class Vec &a, class Vec &b);
            TSP_NUM        getMix(class Vec *a, class Vec *b);
            TSP_NUM        getMix(class Vec *a, class Vec &b);
            TSP_NUM        getMix(class Vec &a, class Vec *b);
            Vec&              Set(class Vec &v);
            Vec&              Set(class Vec *v);
            Vec&              Set(TSP_NUM x, TSP_NUM y, TSP_NUM z);
            Vec&              Set(TSP_NUM x, TSP_NUM y);
            Vec&              Set(TSP_NUM x);
            Vec&              Offset(class Vec &Dir, TSP_NUM n);
            Vec&              Offset(class Vec *Dir, TSP_NUM n);
            class Vec      getOffset(class Vec &Dir, TSP_NUM n);
            class Vec      getOffset(class Vec *Dir, TSP_NUM n);
            Vec&              Cross(class Vec *v);
            Vec&              Cross(class Vec &v);
            class Vec      getCross(class Vec *v);
            class Vec      getCross(class Vec &v);
            TSP_NUM        getDot(class Vec *v);
            TSP_NUM        getDot(class Vec &v);
            Vec&              RollR(void);
            class Vec      getRollR(void);
            Vec&              RollL(void);
            class Vec      getRollL(void);
            Vec&              Swap(const char* Comp);
            class Vec      getSwap(const char* Comp);
            Vec&              Print(void);
            Vec&              PrintTrajectory(void);
                              Vec(const char *N, TSP_NUM x, TSP_NUM y, TSP_NUM z, TSP_KEY k, class Vec *Next);
                              Vec(const char *N, TSP_NUM x, TSP_NUM y, TSP_NUM z, class Vec *Next);
                              Vec(const char *N, TSP_NUM x, TSP_NUM y, TSP_NUM z);
                              Vec(const char *N);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z);
                              Vec(TSP_NUM x, TSP_NUM y);
                              Vec(TSP_NUM x);
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

    Vec::Vec(const char *Name, TSP_NUM x, TSP_NUM y, TSP_NUM z, TSP_KEY k, class Vec *Next)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(k);
      setName(Name);
      setNext(Next);
    }

    Vec::Vec(const char *Name, TSP_NUM x, TSP_NUM y, TSP_NUM z, class Vec *Next)
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

    Vec::Vec(const char *Name, TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(Name);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setKey(0);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y)
    {
      setX(x);
      setY(y);
      setZ(0.0);
      setKey(0);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x)
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

    TSP_STR Vec::isOrthogonal(class Vec *v)
    {
      if(v == NULL){ return 0x00; }
      if(getDot(v) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_STR Vec::isOrthogonal(class Vec &v)
    {
      if(getDot(v) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_STR Vec::isCollinear(class Vec *v)
    {
      if(v == NULL){ return 0x00; }
      TSP_NUM x = getX() / v->getX();
      TSP_NUM y = getY() / v->getY();
      TSP_NUM z = getZ() / v->getZ();
      if(x == y && y == z && z == x){ return 0xFF; }
      return 0x00;
    }

    TSP_STR Vec::isCollinear(class Vec &v)
    {
      TSP_NUM x = getX() / v.getX();
      TSP_NUM y = getY() / v.getY();
      TSP_NUM z = getZ() / v.getZ();
      if(x == y && y == z && z == x){ return 0xFF; }
      return 0x00;
    }

    TSP_NUM Vec::getDistance(void)
    {
      return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
    }

    TSP_NUM Vec::getDistance(class Vec *v)
    {
      if(v == NULL){ return getDistance(); }
      return sqrt((getX() - v->getX()) * (getX() - v->getX()) +
                  (getY() - v->getY()) * (getY() - v->getY()) +
                  (getZ() - v->getZ()) * (getZ() - v->getZ()));
    }

    TSP_NUM Vec::getDistance(class Vec &v)
    {
      return sqrt((getX() - v.getX()) * (getX() - v.getX()) +
                  (getY() - v.getY()) * (getY() - v.getY()) +
                  (getZ() - v.getZ()) * (getZ() - v.getZ()));
    }

    Vec Vec::getDirection(void)
    {
      TSP_NUM D = getDistance();
      if(D == 0){ return Vec("FAIL"); }
      return Vec(getX() / D, getY() / D, getZ() / D);
    }

    Vec Vec::getDirection(class Vec *v)
    {
      if(v == NULL){ return getDirection(); }
      TSP_NUM D = getDistance(v);
      if(D == 0){ return Vec("FAIL"); }
      return Vec((getX() - v->getX()) / D, (getY() - v->getY()) / D, (getZ() - v->getZ()) / D);
    }

    Vec Vec::getDirection(class Vec &v)
    {
      TSP_NUM D = getDistance(&v);
      if(D == 0){ return Vec("FAIL"); }
      return Vec((getX() - v.getX()) / D, (getY() - v.getY()) / D, (getZ() - v.getZ()) / D);
    }

    Vec& Vec::Direction(void)
    {
      TSP_NUM D = getDistance();
      if(D == 0){ return *this; }
      setX(getX() / D);
      setY(getY() / D);
      setZ(getZ() / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec *v)
    {
      if(v == NULL){ return Direction(); }
      TSP_NUM D = getDistance(v);
      if(D == 0){ return *this; }
      setX((getX() - v->getX()) / D);
      setY((getY() - v->getY()) / D);
      setZ((getZ() - v->getZ()) / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec &v)
    {
      TSP_NUM D = getDistance(&v);
      if(D == 0){ return *this; }
      setX((getX() - v.getX()) / D);
      setY((getY() - v.getY()) / D);
      setZ((getZ() - v.getZ()) / D);
      return *this;
    }

    Vec operator^(Vec &a, Vec &b)
    {
      return a.getCross(b);
    }

    TSP_NUM operator*(Vec &a, Vec &b)
    {
      return a.getDot(b);
    }

    Vec operator+(Vec &a, Vec &b)
    {
      return  Vec(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
    }

    Vec operator-(Vec &a, Vec &b)
    {
      return  Vec(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
    }

    void operator+=(Vec &a, TSP_NUM b)
    {
      a.setX(a.getX() + b);
    }

    void operator+=(Vec &a, Vec &b)
    {
      a.setX(a.getX() + b.getX());
      a.setY(a.getY() + b.getY());
      a.setZ(a.getZ() + b.getZ());
    }

    void operator^=(Vec &a, Vec &b)
    {
      a.Cross(b);
    }

    void operator*=(Vec &a, Vec &b)
    {
      a.Mul(a.getDot(b));
    }

    void operator-=(Vec &a, TSP_NUM b)
    {
      a.setX(a.getX() - b);
    }

    void operator-=(Vec &a, Vec &b)
    {
      a.setX(a.getX() - b.getX());
      a.setY(a.getY() - b.getY());
      a.setZ(a.getZ() - b.getZ());
    }

    Vec operator*(TSP_NUM a, Vec &b)
    {
      return Vec(a * b.getX(), a * b.getY(), a * b.getZ());
    }

    Vec operator*(Vec &b, TSP_NUM a)
    {
      return Vec(a * b.getX(), a * b.getY(), a * b.getZ());
    }

    Vec  operator/(Vec &b, TSP_NUM a)
    {
      if(a == 0){ return Vec("FAIL"); }
      return Vec(b.getX() / a, b.getY() / a, b.getZ() / a);
    }

    void operator*=(Vec &a, TSP_NUM b)
    {
      a.setX(a.getX() * b);
      a.setY(a.getY() * b);
      a.setZ(a.getZ() * b);
    }

    void operator/=(Vec &a, TSP_NUM b)
    {
      if(b == 0){ return; }
      a.setX(a.getX() / b);
      a.setY(a.getY() / b);
      a.setZ(a.getZ() / b);
    }

    TSP_STR operator==(Vec &a, Vec &b)
    {
      if((a.getX() == b.getX()) &&
         (a.getY() == b.getY()) &&
         (a.getZ() == b.getZ())){ return 0xFF; }
      return 0x00;
    }

    TSP_STR operator!=(Vec &a, Vec &b)
    {
      if((a.getX() != b.getX()) ||
         (a.getY() != b.getY()) ||
         (a.getZ() != b.getZ())){ return 0xFF; }
      return 0x00;
    }

    TSP_STR operator>=(Vec &a, Vec &b)
    {
      if(a.getDistance() >= b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    TSP_STR operator<=(Vec &a, Vec &b)
    {
      if(a.getDistance() <= b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    TSP_STR operator>(Vec &a, Vec &b)
    {
      if(a.getDistance() > b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    TSP_STR operator<(Vec &a, Vec &b)
    {
      if(a.getDistance() < b.getDistance()){ return 0xFF; }
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

    TSP_NUM Vec::getAngleRad(class Vec *v)
    {
      if(v == NULL){ return 0; }
      TSP_NUM Dot = getDot(v);
      TSP_NUM Abs = getDistance();
      TSP_NUM Abv = v->getDistance();
      if(Abs == 0 || Abv == 0){ return 0; }
      return acos(Dot / ( Abs * Abv ));
    }

    TSP_NUM Vec::getAngleRad(class Vec &v)
    {
      TSP_NUM Dot = getDot(&v);
      TSP_NUM Abs = getDistance();
      TSP_NUM Abv = v.getDistance();
      if(Abs == 0 || Abv == 0){ return 0; }
      return acos(Dot / ( Abs * Abv ));
    }

    TSP_NUM Vec::getAngleDeg(class Vec &v)
    {
      return ( getAngleRad(&v) * ( 180 / TSP_PI));
    }

    TSP_NUM Vec::getAngleDeg(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return ( getAngleRad(v) * ( 180 / TSP_PI));
    }

    Vec& Vec::Project(class Vec *v)
    {
      if(v == NULL){ return *this; }
      TSP_NUM CpyX = v->getX();
      TSP_NUM CpyY = v->getY();
      TSP_NUM CpyZ = v->getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return *this; }
      TSP_NUM Dotp = getDot(v) / Dst2;
      Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      return *this;
    }

    Vec& Vec::Project(class Vec &v)
    {
      TSP_NUM CpyX = v.getX();
      TSP_NUM CpyY = v.getY();
      TSP_NUM CpyZ = v.getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return *this; }
      TSP_NUM Dotp = getDot(v) / Dst2;
      Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      return *this;
    }

    Vec Vec::getProject(class Vec *v)
    {
      if(v == NULL){ return Vec("FAIL"); }
      TSP_NUM CpyX = v->getX();
      TSP_NUM CpyY = v->getY();
      TSP_NUM CpyZ = v->getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return Vec("FAIL"); }
      TSP_NUM Dotp  = getDot(v) / Dst2;
      return Vec(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
    }

    Vec Vec::getProject(class Vec &v)
    {
      TSP_NUM CpyX = v.getX();
      TSP_NUM CpyY = v.getY();
      TSP_NUM CpyZ = v.getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return Vec("FAIL"); }
      TSP_NUM Dotp = getDot(v) / Dst2;
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

    TSP_NUM Vec::getDot(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return (getX()*v->getX() +
              getY()*v->getY() +
              getZ()*v->getZ());
    }

    TSP_NUM Vec::getDot(class Vec &v)
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
      TSP_NUM x = getX() + v->getX();
      TSP_NUM y = getY() + v->getY();
      TSP_NUM z = getZ() + v->getZ();
      return Vec(x, y, z);
    }

    Vec Vec::getAdd(class Vec &v)
    {
      TSP_NUM x = getX() + v.getX();
      TSP_NUM y = getY() + v.getY();
      TSP_NUM z = getZ() + v.getZ();
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
      TSP_NUM x = getX() - v->getX();
      TSP_NUM y = getY() - v->getY();
      TSP_NUM z = getZ() - v->getZ();
      return Vec(x, y, z);
  }

    Vec Vec::getSub(class Vec &v)
    {
      TSP_NUM x = getX() - v.getX();
      TSP_NUM y = getY() - v.getY();
      TSP_NUM z = getZ() - v.getZ();
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

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x);
      setY(y);
      setZ(z);
      return *this;
    }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y)
    {
      setX(x);
      setY(y);
      setZ(0);
      return *this;
    }

    Vec& Vec::Set(TSP_NUM x)
    {
      setX(x);
      setY(0);
      setZ(0);
      return *this;
    }

    TSP_NUM Vec::getCosine(TSP_STR Axis)
    {
      TSP_NUM Abs = getDistance();
      if(Abs  ==  0 ){ return 0; }
      if(Axis == 'x'){ return getX() / Abs; }
      if(Axis == 'y'){ return getY() / Abs; }
      if(Axis == 'z'){ return getZ() / Abs; }
      return 0;
    }

    Vec& Vec::Mul(TSP_NUM n)
    {
      setX(getX() * n);
      setY(getY() * n);
      setZ(getZ() * n);
      return *this;
    }

    Vec Vec::getMul(TSP_NUM n)
    {
      return Vec(getX() * n, getY() * n, getZ() * n);
    }

    Vec& Vec::Div(TSP_NUM n)
    {
      if(n == 0){ return *this; }
      setX(getX() / n);
      setY(getY() / n);
      setZ(getZ() / n);
      return *this;
    }

    Vec Vec::getDiv(TSP_NUM n)
    {
      if(n == 0){ return Vec("FAIL"); }
      return Vec(getX() / n, getY() / n, getZ() / n);
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return fabs(getCross(v).getDistance());
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec &v)
    {
      return fabs(getCross(v).getDistance());
    }

    TSP_NUM Vec::getAreaTriangle(class Vec *v)
    {
      if(v == NULL){ return 0; }
      return fabs(0.5 * getAreaParallelogram(v));
    }

    TSP_NUM Vec::getAreaTriangle(class Vec &v)
    {
      return fabs(0.5 * getAreaParallelogram(v));
    }

    TSP_NUM Vec::getMix(class Vec &a, class Vec &b)
    {
      cVec T = a.getCross(b);
      return getDot(T);
    }

    TSP_NUM Vec::getMix(class Vec *a, class Vec *b)
    {
      if(a == NULL || b == NULL){ return 0.0; }
      cVec T = a->getCross(b);
      return getDot(T);
    }

    TSP_NUM Vec::getMix(class Vec *a, class Vec &b)
    {
      if(a == NULL){ return 0.0; }
      cVec T = a->getCross(b);
      return getDot(T);
    }

    TSP_NUM Vec::getMix(class Vec &a, class Vec *b)
    {
      if(b == NULL){ return 0.0; }
      cVec T = a.getCross(b);
      return getDot(T);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &a, class Vec &b)
    {
      return fabs(getMix(a,b) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *a, class Vec *b)
    {
      if(a == NULL || b == NULL){ return 0; }
      return fabs(getMix(a,b) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *a, class Vec &b)
    {
      if(a == NULL){ return 0; }
      return fabs(getMix(a,b) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &a, class Vec *b)
    {
      if(b == NULL){ return 0; }
      return fabs(getMix(a,b) / 6);
    }

    TSP_STR Vec::isCoplanar(class Vec &a, class Vec &b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_STR Vec::isCoplanar(class Vec *a, class Vec *b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_STR Vec::isCoplanar(class Vec &a, class Vec *b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_STR Vec::isCoplanar(class Vec *a, class Vec &b)
    {
      if(getMix(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    Vec& Vec::Offset(class Vec *Dir, TSP_NUM n)
    {
      if(Dir == NULL){ return *this; }
      cVec D = Dir->getDirection();
           D.Mul(n);
      setX(getX() + D.getX());
      setY(getY() + D.getY());
      setZ(getZ() + D.getZ());
      return *this;
    }

    Vec& Vec::Offset(class Vec &Dir, TSP_NUM n)
    {
      cVec D = Dir.getDirection();
           D.Mul(n);
      setX(getX() + D.getX());
      setY(getY() + D.getY());
      setZ(getZ() + D.getZ());
      return *this;
    }

    Vec Vec::getOffset(class Vec *Dir, TSP_NUM n)
    {
      if(Dir == NULL){ return Vec("FAIL"); }
      cVec D = Dir->getDirection();
           D.Mul(n);
      return Vec((getX() + D.getX()),
                 (getY() + D.getY()),
                 (getZ() + D.getZ()));
    }

    Vec Vec::getOffset(class Vec &Dir, TSP_NUM n)
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
      TSP_NUM T = Z;
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
      TSP_NUM T = X;
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
      TSP_NUM T = 0;
      TSP_STR  arswap[3] = {0};
      TSP_KEY len = strlen(Comp);
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
      TSP_STR  arswap[3] = {0};
      TSP_KEY len = strlen(Comp);
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
