#ifndef __TSP_VECTOR__H_
    #define __TSP_VECTOR__H_               // Types are MCU dependent
    #define TSP_NUM float                  // General type for floating point number
    #define TSP_STR unsigned char          // General type for strings storage in vector names
    #define TSP_BUL unsigned char          // General type for representing booleans
    #define TSP_PI 3.141592653589793238462643383279502884197169399375105820974944
    typedef class Vec
    {
        private:
            TSP_NUM X;
            TSP_NUM Y;
            TSP_NUM Z;
            void      *User;
            TSP_STR   *Name;
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
            friend TSP_BUL operator==(Vec&, Vec&);
            friend TSP_BUL operator!=(Vec&, Vec&);
            friend TSP_BUL operator>=(Vec&, Vec&);
            friend TSP_BUL operator<=(Vec&, Vec&);
            friend TSP_BUL operator> (Vec&, Vec&);
            friend TSP_BUL operator< (Vec&, Vec&);
            friend class Vec  operator++(Vec&, int);
            friend class Vec  operator--(Vec&, int);
            friend class Vec& operator++(Vec&);
            friend class Vec& operator--(Vec&);
            TSP_BUL         isCollinear (class Vec *b);
            TSP_BUL         isCollinear (class Vec &b);
            TSP_BUL         isOrthogonal(class Vec *b);
            TSP_BUL         isOrthogonal(class Vec &b);
            TSP_BUL         isCoplanar(class Vec &a, class Vec &b);
            TSP_BUL         isCoplanar(class Vec *a, class Vec *b);
            TSP_BUL         isCoplanar(class Vec *a, class Vec &b);
            TSP_BUL         isCoplanar(class Vec &a, class Vec *b);
            TSP_NUM        getDistance(class Vec *b);
            TSP_NUM        getDistance(class Vec &b);
            TSP_NUM        getDistance(void);
            class Vec&        Direction(class Vec *b);
            class Vec&        Direction(class Vec &b);
            class Vec&        Direction(void);
            class Vec      getDirection(class Vec *b);
            class Vec      getDirection(class Vec &b);
            class Vec      getDirection(void);
            TSP_NUM        getX(){ return X; };
            TSP_NUM        getY(){ return Y; };
            TSP_NUM        getZ(){ return Z; };
            void          *getUser(){ return User; };
            TSP_STR       *getName(){ return Name; };
            class Vec     *getNext(){ return Next; };
            class Vec&     setX(TSP_NUM x){ X = x; return *this; };
            class Vec&     setY(TSP_NUM y){ Y = y; return *this; };
            class Vec&     setZ(TSP_NUM z){ Z = z; return *this; };
            class Vec&     setUser(void *pUser){ User = pUser; return *this; };
            class Vec&     setName(const char *pName){ Name = (TSP_STR*)pName; return *this; };
            class Vec&     setNext(class  Vec *pNext){ Next = pNext;      return *this; };
            TSP_NUM        getAngleDeg(class  Vec *b);
            TSP_NUM        getAngleDeg(class  Vec &b);
            TSP_NUM        getAngleRad(class  Vec *b);
            TSP_NUM        getAngleRad(class  Vec &b);
            TSP_NUM        getAreaTriangle(class Vec *b);
            TSP_NUM        getAreaTriangle(class Vec &b);
            TSP_NUM        getAreaParallelogram(class Vec *b);
            TSP_NUM        getAreaParallelogram(class Vec &b);
            TSP_NUM        getVolumeTetrahedron(class Vec &b, class Vec &c);
            TSP_NUM        getVolumeTetrahedron(class Vec *b, class Vec *c);
            TSP_NUM        getVolumeTetrahedron(class Vec *b, class Vec &c);
            TSP_NUM        getVolumeTetrahedron(class Vec &b, class Vec *c);
            TSP_NUM        getVolumeParallelepiped(class Vec &b, class Vec &c);
            TSP_NUM        getVolumeParallelepiped(class Vec *b, class Vec *c);
            TSP_NUM        getVolumeParallelepiped(class Vec *b, class Vec &c);
            TSP_NUM        getVolumeParallelepiped(class Vec &b, class Vec *c);
            class Vec&        Project(class Vec *b);
            class Vec&        Project(class Vec &b);
            class Vec      getProject(class Vec *b);
            class Vec      getProject(class Vec &b);
            class Vec&        Add(class Vec *b);
            class Vec&        Add(class Vec &b);
            class Vec      getAdd(class Vec *b);
            class Vec      getAdd(class Vec &b);
            class Vec&        Sub(class Vec *b);
            class Vec&        Sub(class Vec &b);
            class Vec      getSub(class Vec *b);
            class Vec      getSub(class Vec &b);
            TSP_NUM        getCosine(TSP_STR);
            class Vec&        Neg(void);
            class Vec      getNeg(void);
            class Vec&        Mul(TSP_NUM n);
            class Vec      getMul(TSP_NUM n);
            class Vec&        Div(TSP_NUM n);
            class Vec      getDiv(TSP_NUM n);
            TSP_NUM        getMixed(class Vec &b, class Vec &c);
            TSP_NUM        getMixed(class Vec *b, class Vec *c);
            TSP_NUM        getMixed(class Vec *b, class Vec &c);
            TSP_NUM        getMixed(class Vec &b, class Vec *c);
            class Vec&        CrossTriple(class Vec &b, class Vec &c);
            class Vec&        CrossTriple(class Vec *b, class Vec *c);
            class Vec&        CrossTriple(class Vec *b, class Vec &c);
            class Vec&        CrossTriple(class Vec &b, class Vec *c);
            class Vec      getCrossTriple(class Vec &b, class Vec &c);
            class Vec      getCrossTriple(class Vec *b, class Vec *c);
            class Vec      getCrossTriple(class Vec *b, class Vec &c);
            class Vec      getCrossTriple(class Vec &b, class Vec *c);
            class Vec&        Set(class Vec &b);
            class Vec&        Set(class Vec *b);
            class Vec&        Set(TSP_NUM x, TSP_NUM y, TSP_NUM z);
            class Vec&        Set(TSP_NUM x, TSP_NUM y);
            class Vec&        Set(TSP_NUM x);
            class Vec&        Offset(class Vec &Dir, TSP_NUM n);
            class Vec&        Offset(class Vec *Dir, TSP_NUM n);
            class Vec      getOffset(class Vec &Dir, TSP_NUM n);
            class Vec      getOffset(class Vec *Dir, TSP_NUM n);
            class Vec&        Cross(class Vec *b);
            class Vec&        Cross(class Vec &b);
            class Vec      getCross(class Vec *b);
            class Vec      getCross(class Vec &b);
            TSP_NUM        getDot(Vec *b);
            TSP_NUM        getDot(class Vec &b);
            class Vec&        RollR(void);
            class Vec      getRollR(void);
            class Vec&        RollL(void);
            class Vec      getRollL(void);
            class Vec&        Swap(const char* Comp);
            class Vec      getSwap(const char* Comp);
            class Vec&        Print(void);
            class Vec&        PrintTrajectory(void);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const char *name, void *user, class Vec *next);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const char *name, class Vec *next);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const char *name);
                              Vec(const char *N);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z);
                              Vec(TSP_NUM x, TSP_NUM y);
                              Vec(TSP_NUM x);
                              Vec();
                             ~Vec();
    } cVec;

    Vec& Vec::Print(void)
    {
      printf("\n\rVec %p > %p --> %s, %p\n\rXYZ = { %10.4f, %10.4f, %10.4f }\n\r",
         this,getNext(),getName(),getUser(),getX(),getY(),getZ());
      return *this;
    }

    Vec& Vec::PrintTrajectory(void)
    {
      cVec *p = this;
      while(p != NULL)
      {
        p->Print();
        p = p->getNext();
      }
      return *this;
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const char *name, void *user, class Vec *next)
    {
      setX(x);
      setY(y);
      setZ(z);
      setUser(user);
      setName(name);
      setNext(next);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const char *name, class Vec *next)
    {
      setX(x);
      setY(y);
      setZ(z);
      setUser(NULL);
      setName(name);
      setNext(next);
    }
    Vec::Vec(const char *name)
    {
      setX(0.0);
      setY(0.0);
      setZ(0.0);
      setUser(NULL);
      setName(name);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const char *name)
    {
      setX(x);
      setY(y);
      setZ(z);
      setUser(NULL);
      setName(name);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x);
      setY(y);
      setZ(z);
      setUser(NULL);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y)
    {
      setX(x);
      setY(y);
      setZ(0.0);
      setUser(NULL);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec(TSP_NUM x)
    {
      setX(x);
      setY(0.0);
      setZ(0.0);
      setUser(NULL);
      setName(NULL);
      setNext(NULL);
    }

    Vec::Vec()
    {
      setX(0.0);
      setY(0.0);
      setZ(0.0);
      setUser(NULL);
      setName(NULL);
      setNext(NULL);
    }

    Vec::~Vec()
    {
      free(getName());
    }

    TSP_BUL Vec::isOrthogonal(class Vec *b)
    {
      if(b == NULL){ return 0x00; }
      if(getDot(b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL Vec::isOrthogonal(class Vec &b)
    {
      if(getDot(b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL Vec::isCollinear(class Vec *b)
    {
      if(b == NULL){ return 0x00; }
      TSP_NUM x = getX() / b->getX();
      TSP_NUM y = getY() / b->getY();
      TSP_NUM z = getZ() / b->getZ();
      if(x == y && y == z && z == x){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL Vec::isCollinear(class Vec &b)
    {
      TSP_NUM x = getX() / b.getX();
      TSP_NUM y = getY() / b.getY();
      TSP_NUM z = getZ() / b.getZ();
      if(x == y && y == z && z == x){ return 0xFF; }
      return 0x00;
    }

    TSP_NUM Vec::getDistance(void)
    {
      TSP_NUM x = getX();
      TSP_NUM y = getY();
      TSP_NUM z = getZ();
      return sqrt(x*x + y*y + z*z);
    }

    TSP_NUM Vec::getDistance(class Vec *b)
    {
      if(b == NULL){ return getDistance(); }
      TSP_NUM x = getX() - b->getX();
      TSP_NUM y = getY() - b->getY();
      TSP_NUM z = getZ() - b->getZ();
      return sqrt(x*x + y*y + z*z);
    }

    TSP_NUM Vec::getDistance(class Vec &b)
    {
      TSP_NUM x = getX() - b.getX();
      TSP_NUM y = getY() - b.getY();
      TSP_NUM z = getZ() - b.getZ();
      return sqrt(x*x + y*y + z*z);
    }

    Vec Vec::getDirection(void)
    {
      TSP_NUM D = getDistance();
      if(D == 0){ return Vec("FAIL"); }
      return Vec(getX() / D, getY() / D, getZ() / D);
    }

    Vec Vec::getDirection(class Vec *b)
    {
      if(b == NULL){ return getDirection(); }
      TSP_NUM D = getDistance(b);
      if(D == 0){ return Vec("FAIL"); }
      return Vec((getX() - b->getX()) / D, (getY() - b->getY()) / D, (getZ() - b->getZ()) / D);
    }

    Vec Vec::getDirection(class Vec &b)
    {
      TSP_NUM D = getDistance(&b);
      if(D == 0){ return Vec("FAIL"); }
      return Vec((getX() - b.getX()) / D, (getY() - b.getY()) / D, (getZ() - b.getZ()) / D);
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

    Vec& Vec::Direction(class Vec *b)
    {
      if(b == NULL){ return Direction(); }
      TSP_NUM D = getDistance(b);
      if(D == 0){ return *this; }
      setX((getX() - b->getX()) / D);
      setY((getY() - b->getY()) / D);
      setZ((getZ() - b->getZ()) / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec &b)
    {
      TSP_NUM D = getDistance(&b);
      if(D == 0){ return *this; }
      setX((getX() - b.getX()) / D);
      setY((getY() - b.getY()) / D);
      setZ((getZ() - b.getZ()) / D);
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
      return Vec(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
    }

    Vec operator-(Vec &a, Vec &b)
    {
      return Vec(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
    }

    void operator+=(Vec &a, TSP_NUM b)
    {
      a.setX(a.getX() + b);
    }

    void operator+=(Vec &a, Vec &b)
    {
      a.Add(b);
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
      a.Sub(b);
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
      a.Mul(b);
    }

    void operator/=(Vec &a, TSP_NUM b)
    {
      if(b == 0){ return; }
      a.Div(b);
    }

    TSP_BUL operator==(Vec &a, Vec &b)
    {
      if((a.getX() == b.getX()) &&
         (a.getY() == b.getY()) &&
         (a.getZ() == b.getZ())){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL operator!=(Vec &a, Vec &b)
    {
      if((a.getX() != b.getX()) ||
         (a.getY() != b.getY()) ||
         (a.getZ() != b.getZ())){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL operator>=(Vec &a, Vec &b)
    {
      if(a.getDistance() >= b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL operator<=(Vec &a, Vec &b)
    {
      if(a.getDistance() <= b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL operator>(Vec &a, Vec &b)
    {
      if(a.getDistance() > b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL operator<(Vec &a, Vec &b)
    {
      if(a.getDistance() < b.getDistance()){ return 0xFF; }
      return 0x00;
    }

    Vec operator++(Vec &b, int a)
    {
      cVec Dr = b.getDirection();
      b.Add(Dr); Dr.Sub(b).Neg();
      return Dr;
    }

    Vec operator--(Vec &b, int a)
    {
      cVec Dr = b.getDirection();
      b.Sub(Dr); Dr.Add(b);
      return Dr;
    }

    Vec& operator++(Vec &b)
    {
      cVec Dr = b.getDirection();
      b.Add(Dr); return b;
    }

    Vec& operator--(Vec &b)
    {
      cVec Dr = b.getDirection();
      b.Sub(Dr); return b;
    }

    TSP_NUM Vec::getAngleRad(class Vec *b)
    {
      if(b == NULL){ return 0; }
      TSP_NUM Dot = getDot(b);
      TSP_NUM Abs = getDistance();
      TSP_NUM Abv = b->getDistance();
      if(Abs == 0 || Abv == 0){ return 0; }
      return acos(Dot / ( Abs * Abv ));
    }

    TSP_NUM Vec::getAngleRad(class Vec &b)
    {
      TSP_NUM Dot = getDot(&b);
      TSP_NUM Abs = getDistance();
      TSP_NUM Abv = b.getDistance();
      if(Abs == 0 || Abv == 0){ return 0; }
      return acos(Dot / ( Abs * Abv ));
    }

    TSP_NUM Vec::getAngleDeg(class Vec &b)
    {
      return ( getAngleRad(&b) * ( 180 / TSP_PI));
    }

    TSP_NUM Vec::getAngleDeg(class Vec *b)
    {
      if(b == NULL){ return 0; }
      return ( getAngleRad(b) * ( 180 / TSP_PI));
    }

    Vec& Vec::Project(class Vec *b)
    {
      if(b == NULL){ return *this; }
      TSP_NUM CpyX = b->getX();
      TSP_NUM CpyY = b->getY();
      TSP_NUM CpyZ = b->getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return *this; }
      TSP_NUM Dotp = getDot(b) / Dst2;
      Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      return *this;
    }

    Vec& Vec::Project(class Vec &b)
    {
      TSP_NUM CpyX = b.getX();
      TSP_NUM CpyY = b.getY();
      TSP_NUM CpyZ = b.getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return *this; }
      TSP_NUM Dotp = getDot(b) / Dst2;
      Set(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
      return *this;
    }

    Vec Vec::getProject(class Vec *b)
    {
      if(b == NULL){ return Vec("FAIL"); }
      TSP_NUM CpyX = b->getX();
      TSP_NUM CpyY = b->getY();
      TSP_NUM CpyZ = b->getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return Vec("FAIL"); }
      TSP_NUM Dotp  = getDot(b) / Dst2;
      return Vec(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
    }

    Vec Vec::getProject(class Vec &b)
    {
      TSP_NUM CpyX = b.getX();
      TSP_NUM CpyY = b.getY();
      TSP_NUM CpyZ = b.getZ();
      TSP_NUM Dst2 = CpyX*CpyX + CpyY*CpyY + CpyZ*CpyZ;
      if(Dst2 == 0){ return Vec("FAIL"); }
      TSP_NUM Dotp = getDot(b) / Dst2;
      return Vec(Dotp*CpyX, Dotp*CpyY, Dotp*CpyZ);
    }

    Vec& Vec::Cross(class Vec *b)
    {
      if(b == NULL){ return *this; }
      Set((getY() * b->getZ()) - (getZ() * b->getY()),
          (getZ() * b->getX()) - (getX() * b->getZ()),
          (getX() * b->getY()) - (getY() * b->getX()));
      return *this;
    }

    Vec& Vec::Cross(class Vec &b)
    {
      Set((getY() * b.getZ()) - (getZ() * b.getY()),
          (getZ() * b.getX()) - (getX() * b.getZ()),
          (getX() * b.getY()) - (getY() * b.getX()));
      return *this;
    }

    Vec Vec::getCross(class Vec *b)
    {
      if(b == NULL){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).Cross(b); return v;
    }

    Vec Vec::getCross(class Vec &b)
    {
      cVec v = Vec().Set(this).Cross(b); return v;
    }

    Vec& Vec::CrossTriple(class Vec &b, class Vec &c)
    {
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b.getX()) - (ab * c.getX()),
          (ac * b.getY()) - (ab * c.getY()),
          (ac * b.getZ()) - (ab * c.getZ()));
      return *this;
    }

    Vec& Vec::CrossTriple(class Vec *b, class Vec *c)
    {
      if(b == NULL || c == NULL){ return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b->getX()) - (ab * c->getX()),
          (ac * b->getY()) - (ab * c->getY()),
          (ac * b->getZ()) - (ab * c->getZ()));
      return *this;
    }
    Vec& Vec::CrossTriple(class Vec *b, class Vec &c)
    {
      if(b == NULL){ return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b->getX()) - (ab * c.getX()),
          (ac * b->getY()) - (ab * c.getY()),
          (ac * b->getZ()) - (ab * c.getZ()));
      return *this;
    }

    Vec& Vec::CrossTriple(class Vec &b, class Vec *c)
    {
      if(c == NULL){ return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b.getX()) - (ab * c->getX()),
          (ac * b.getY()) - (ab * c->getY()),
          (ac * b.getZ()) - (ab * c->getZ()));
      return *this;
    }

    Vec Vec::getCrossTriple(class Vec &b, class Vec &c)
    {
      cVec v = Vec().Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec *b, class Vec *c)
    {
      if(b == NULL || c == NULL){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec *b, class Vec &c)
    {
      if(b == NULL){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec &b, class Vec *c)
    {
      if(c == NULL){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).CrossTriple(b,c); return v;
    }

    TSP_NUM Vec::getDot(class Vec *b)
    {
      if(b == NULL){ return 0; }
      return (getX()*b->getX() +
              getY()*b->getY() +
              getZ()*b->getZ());
    }

    TSP_NUM Vec::getDot(class Vec &b)
    {
      return (getX()*b.getX() +
              getY()*b.getY() +
              getZ()*b.getZ());
    }

    Vec& Vec::Add(class Vec *b)
    {
      if(b == NULL){ return *this; }
      setX(getX() + b->getX());
      setY(getY() + b->getY());
      setZ(getZ() + b->getZ());
      return *this;
    }

    Vec& Vec::Add(class Vec &b)
    {
      setX(getX() + b.getX());
      setY(getY() + b.getY());
      setZ(getZ() + b.getZ());
      return *this;
    }

    Vec Vec::getAdd(class Vec *b)
    {
      if(b == NULL){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).Add(b); return v;
    }

    Vec Vec::getAdd(class Vec &b)
    {
      cVec v = Vec().Set(this).Add(b); return v;
    }

    Vec& Vec::Sub(class Vec *b)
    {
      if(b == NULL){ return *this; }
      setX(getX() - b->getX());
      setY(getY() - b->getY());
      setZ(getZ() - b->getZ());
      return *this;
    }

    Vec& Vec::Sub(class Vec &b)
    {
      setX(getX() - b.getX());
      setY(getY() - b.getY());
      setZ(getZ() - b.getZ());
      return *this;
    }

    Vec Vec::getSub(class Vec *b)
    {
      if(b == NULL){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).Sub(b); return v;
    }

    Vec Vec::getSub(class Vec &b)
    {
      cVec v = Vec().Set(this).Sub(b); return v;
    }

    Vec& Vec::Set(class Vec *b)
    {
      if(b == NULL){ return *this; }
      setX(b->getX());
      setY(b->getY());
      setZ(b->getZ());
      return *this;
    }

    Vec& Vec::Set(class Vec &b)
    {
      setX(b.getX());
      setY(b.getY());
      setZ(b.getZ());
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
      cVec v = Vec().Set(this).Mul(n); return v;
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
      cVec v = Vec().Set(this).Div(n); return v;
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec *b)
    {
      if(b == NULL){ return 0; }
      return fabs(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec &b)
    {
      return fabs(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaTriangle(class Vec *b)
    {
      if(b == NULL){ return 0; }
      return fabs(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getAreaTriangle(class Vec &b)
    {
      return fabs(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getMixed(class Vec &b, class Vec &c)
    {
      cVec T = b.getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getMixed(class Vec *b, class Vec *c)
    {
      if(b == NULL || c == NULL){ return 0.0; }
      cVec T = b->getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getMixed(class Vec *b, class Vec &c)
    {
      if(b == NULL){ return 0.0; }
      cVec T = b->getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getMixed(class Vec &b, class Vec *c)
    {
      if(c == NULL){ return 0.0; }
      cVec T = b.getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec &b, class Vec &c)
    {
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec *b, class Vec *c)
    {
      if(b == NULL || c == NULL){ return 0; }
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec *b, class Vec &c)
    {
      if(b == NULL){ return 0; }
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec &b, class Vec *c)
    {
      if(c == NULL){ return 0; }
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &b, class Vec &c)
    {
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *b, class Vec *c)
    {
      if(b == NULL || c == NULL){ return 0; }
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *b, class Vec &c)
    {
      if(b == NULL){ return 0; }
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &b, class Vec *c)
    {
      if(c == NULL){ return 0; }
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_BUL Vec::isCoplanar(class Vec &a, class Vec &b)
    {
      if(getMixed(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL Vec::isCoplanar(class Vec *a, class Vec *b)
    {
      if(getMixed(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL Vec::isCoplanar(class Vec &a, class Vec *b)
    {
      if(getMixed(a,b) == 0){ return 0xFF; }
      return 0x00;
    }

    TSP_BUL Vec::isCoplanar(class Vec *a, class Vec &b)
    {
      if(getMixed(a,b) == 0){ return 0xFF; }
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
      cVec v = Vec().Set(this).Offset(Dir,n); return v;
    }

    Vec Vec::getOffset(class Vec &Dir, TSP_NUM n)
    {
      cVec v = Vec().Set(this).Offset(Dir,n); return v;
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
      cVec v = Vec().Set(this).Neg(); return v;
    }

    Vec& Vec::RollL(void)
    {  // X Y Z  ->  Z X Y
      TSP_NUM T = Z; Z = Y;
              Y = X; X = T;
      return *this;
    }

    Vec Vec::getRollL(void)
    {  // X Y Z  ->  Z X Y
      return Vec(Z,X,Y);
    }

    Vec& Vec::RollR(void)
    {  // X Y Z  ->  Y Z X
      TSP_NUM T = X; X = Y;
              Y = Z; Z = T;
      return *this;
    }

    Vec Vec::getRollR(void)
    {  // X Y Z  ->  Y Z X
      return Vec(Y,Z,X);
    }

    Vec& Vec::Swap(const char* cmp)
    {
      TSP_NUM T        = 0.0;
      TSP_STR swp[2]   = {0};
      unsigned int len = strlen(cmp);
      if(len >= 2)
      {
        swp[0] = cmp[0] | 0x20;
        swp[1] = cmp[1] | 0x20;
        if(!memcmp(swp,"xy",2) || !memcmp(swp,"yx",2))
        {
          T = X; X = Y; Y = T;
        }
        if(!memcmp(swp,"yz",2) || !memcmp(swp,"zy",2))
        {
          T = Y; Y = Z; Z = T;
        }
        if(!memcmp(swp,"zx",2) || !memcmp(swp,"xz",2))
        {
          T = Y; Y = Z; Z = T;
        }
      }
      return *this;
    }

    Vec Vec::getSwap(const char* cmp)
    {
      unsigned int len = strlen(cmp);
      if(len <= 1){ return Vec("FAIL"); }
      cVec v = Vec().Set(this).Swap(cmp); return v;
    }
#endif
