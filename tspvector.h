#ifndef __TSP_VECTOR__H_
    #include <malloc.h>                    // Allocation and memory management
    #include <stdio.h>                     // Console IO
    #include <math.h>                      // Maths
    #include <string.h>                    // Memory move and copy
    #include <stdarg.h>                    // Variable arguments notes
    #define __TSP_VECTOR__H_               // Types are MCU dependent
    #define TSP_NUM float                  // General type for floating point number
    #define TSP_STR unsigned char          // General type for strings storage in vector names
    #define TSP_BUL unsigned char          // General type for representing booleans
    #define TSP_ERR_COD "ERR:"             // General error message prefix
    #define TSP_MSG_LEN 200                // General note length. Also used for internal messages
    #define TSP_ROUND roundf               // General macro for processing rounding
    #define TSP_TRUNC truncf               // General macro for processing truncate
    #define TSP_FLOOR floorf               // General macro for processing floor
    #define TSP_CEIL  ceilf                // General macro for processing ceiling
    #define TSP_ABS   fabs                 // General macro for processing absolute
    #define TSP_PI 3.1415926535897931

    typedef class Vec
    {
        private:
            TSP_NUM X;
            TSP_NUM Y;
            TSP_NUM Z;
            TSP_STR   *Name;
            TSP_STR   *Note;
            void      *User;
            class Vec *Next;
        public:
            friend Vec        operator+ (Vec&, Vec&);
            friend Vec        operator- (Vec&, Vec&);
            friend void       operator+=(Vec&, TSP_NUM);
            friend void       operator+=(Vec&, Vec&);
            friend void       operator-=(Vec&, TSP_NUM);
            friend void       operator-=(Vec&, Vec&);
            friend Vec        operator^ (Vec&, Vec&);
            friend void       operator^=(Vec&, Vec&);
            friend TSP_NUM    operator* (Vec&, Vec&);
            friend Vec        operator* (TSP_NUM , Vec&);
            friend Vec        operator* (Vec&, TSP_NUM);
            friend void       operator*=(Vec&, TSP_NUM);
            friend void       operator*=(Vec&, Vec&);
            friend Vec        operator/ (Vec&, TSP_NUM);
            friend void       operator/=(Vec&, TSP_NUM);
            friend TSP_BUL    operator==(Vec&, Vec&);
            friend TSP_BUL    operator!=(Vec&, Vec&);
            friend TSP_BUL    operator>=(Vec&, Vec&);
            friend TSP_BUL    operator<=(Vec&, Vec&);
            friend TSP_BUL    operator> (Vec&, Vec&);
            friend TSP_BUL    operator< (Vec&, Vec&);
            friend class Vec  operator++(Vec&, int);
            friend class Vec  operator--(Vec&, int);
            friend class Vec& operator++(Vec&);
            friend class Vec& operator--(Vec&);
            TSP_BUL         isZero(void);
            TSP_BUL         isValid(void);
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
            TSP_NUM        getX(void){ return X; };
            TSP_NUM        getY(void){ return Y; };
            TSP_NUM        getZ(void){ return Z; };
            void          *getUser(void){ return User; };
            TSP_STR       *getName(void){ return Name; };
            class Vec     *getNext(void){ return Next; };
            TSP_STR       *getNote(void){ return Note; };
            class Vec&     setNote(const char *form, ...);
            class Vec&     setNote(void){ if(Note != NULL){ free(Note); } Note = NULL; return *this; };
            class Vec&     setX(TSP_NUM x){ X = x; return *this; };
            class Vec&     setY(TSP_NUM y){ Y = y; return *this; };
            class Vec&     setZ(TSP_NUM z){ Z = z; return *this; };
            class Vec&     setUser(void *pUser){ User = pUser; return *this; };
            class Vec&     setName(const void *pName){ Name = (TSP_STR*)pName; return *this; };
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
            class Vec&        Round(void){ X = TSP_ROUND(X); Y = TSP_ROUND(Y); Z = TSP_ROUND(Z); return *this; };
            class Vec      getRound(void);
            class Vec&        RoundDigit(unsigned int d);
            class Vec      getRoundDigit(unsigned int d);
            class Vec&        Trunc(void){ X = TSP_TRUNC(X); Y = TSP_TRUNC(Y); Z = TSP_TRUNC(Z);return *this; };
            class Vec      getTrunc(void);
            class Vec&        Floor(void){ X = TSP_FLOOR(X); Y = TSP_FLOOR(Y); Z = TSP_FLOOR(Z);return *this; };
            class Vec      getFloor(void);
            class Vec&        Ceil(void){ X = ceilf(X); Y = ceilf(Y); Z = ceilf(Z); return *this; };
            class Vec      getCeil(void);
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
            class Vec&        Set(void);
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
            class Vec&        Swap(const void* Comp);
            class Vec      getSwap(const void* Comp);
            class Vec&        Print(void);
            class Vec&        PrintTrajectory(void);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, void *user, class Vec *next);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, class Vec *next);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name);
                              Vec(const void *name);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z);
                              Vec(TSP_NUM x, TSP_NUM y);
                              Vec(TSP_NUM x);
                              Vec(void);
                             ~Vec(void){ free(Name); };
    } cVec;

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, void *user, class Vec *next)
    {
      setX(x); setY(y); setZ(z); setUser(user);
      setName((const TSP_STR*)name); setNext(next); Note = NULL;
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, class Vec *next)
    {
      setX(x); setY(y); setZ(z); setUser(NULL);
      setName((const TSP_STR*)name); setNext(next); Note = NULL;
    }
    Vec::Vec(const void *name)
    {
      setX(0.0); setY(0.0); setZ(0.0); setUser(NULL);
      setName((const TSP_STR*)name); setNext(NULL); Note = NULL;
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name)
    {
      setX(x); setY(y); setZ(z); setUser(NULL);
      setName((const TSP_STR*)name); setNext(NULL); Note = NULL;
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x); setY(y); setZ(z); setUser(NULL); setName(NULL); setNext(NULL); Note = NULL;
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y)
    {
      setX(x); setY(y); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL); Note = NULL;
    }

    Vec::Vec(TSP_NUM x)
    {
      setX(x); setY(0.0); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL); Note = NULL;
    }

    Vec::Vec()
    {
      setX(0.0); setY(0.0); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL); Note = NULL;
    }

    Vec& Vec::Print(void)
    {
      printf("\nVec %p > %p --> %s, %p\n\rXYZ = { %15.8f, %15.8f, %15.8f }",
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

    Vec& Vec::setNote(const char *form, ...)
    {
      va_list args;
      if(NULL != Note){ free(Note); }
      if(NULL == (Note = (TSP_STR*)malloc((TSP_MSG_LEN)*sizeof(TSP_STR)))){ return *this; }
      va_start (args, form); vsprintf((char*)(Note), form, args); va_end(args); return *this;
    }

    TSP_BUL Vec::isValid(void)
    {
      if(NULL == Note){ return (1==1); }
      return memcmp(Note,TSP_ERR_COD,sizeof(TSP_ERR_COD)-1);
    }

    TSP_BUL Vec::isZero(void){ return (X==0 && Y==0 && Z==0); }

    TSP_BUL Vec::isOrthogonal(class Vec *b)
    {
      if(b == NULL){ setNote("%s isOrthogonal(vec*): Argument is null",TSP_ERR_COD); return 0; }
      return (getDot(b) == 0);
    }

    TSP_BUL Vec::isOrthogonal(class Vec &b){ return (getDot(b) == 0); }

    TSP_BUL Vec::isCollinear(class Vec *b)
    {
      if(b == NULL){ setNote("%s isCollinear(vec*): Argument is null",TSP_ERR_COD); return 0; }
      TSP_NUM x = getX() / b->getX();
      TSP_NUM y = getY() / b->getY();
      TSP_NUM z = getZ() / b->getZ();
      return (x == y && y == z && z == x);
    }

    TSP_BUL Vec::isCollinear(class Vec &b)
    {
      TSP_NUM x = getX() / b.getX();
      TSP_NUM y = getY() / b.getY();
      TSP_NUM z = getZ() / b.getZ();
      return (x == y && y == z && z == x);
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

    Vec& Vec::Direction(void)
    {
      TSP_NUM dst = getDistance();
      if(dst == 0){ setNote("%s Direction(void): Base module is zero",TSP_ERR_COD); return *this; }
      setX(getX() / dst);
      setY(getY() / dst);
      setZ(getZ() / dst);
      return *this;
    }

    Vec& Vec::Direction(class Vec *b)
    {
      if(b == NULL){ return Direction(); }
      TSP_NUM dst = getDistance(b);
      if(dst == 0){ setNote("%s Direction(vec*): Base module is zero",TSP_ERR_COD); return *this; }
      setX((getX() - b->getX()) / dst);
      setY((getY() - b->getY()) / dst);
      setZ((getZ() - b->getZ()) / dst);
      return *this;
    }

    Vec& Vec::Direction(class Vec &b)
    {
      TSP_NUM dst = getDistance(&b);
      if(dst == 0){ setNote("%s Direction(vec&): Base module is zero",TSP_ERR_COD); return *this; }
      setX((getX() - b.getX()) / dst);
      setY((getY() - b.getY()) / dst);
      setZ((getZ() - b.getZ()) / dst);
      return *this;
    }

    Vec Vec::getDirection(void)
    {
      cVec v = Vec();
      TSP_NUM dst = getDistance();
      if(dst == 0){ v.setNote("%s getDirection(void): Base module is zero",TSP_ERR_COD); return v; }
      v.Set(this).Direction(); return v;
    }

    Vec Vec::getDirection(class Vec *b)
    {
      if(b == NULL){ return getDirection(); }
      cVec v = Vec();
      TSP_NUM dst = getDistance(b);
      if(dst == 0){ v.setNote("%s getDirection(vec*): Argument module is zero",TSP_ERR_COD); return v; }
      v.Set(this).Direction(b); return v;
    }

    Vec Vec::getDirection(class Vec &b)
    {
      cVec v = Vec();
      TSP_NUM dst = getDistance(&b);
      if  (dst == 0){ v.setNote("%s getDirection(vec&): Argument module is zero",TSP_ERR_COD); return v; }
      v.Set(this).Direction(b); return v;
    }

    Vec operator^(Vec &a, Vec &b){ return a.getCross(b); }

    TSP_NUM operator*(Vec &a, Vec &b){ return a.getDot(b); }

    Vec operator+(Vec &a, Vec &b)
    {
      return Vec(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
    }

    Vec operator-(Vec &a, Vec &b)
    {
      return Vec(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
    }

    void operator+=(Vec &a, TSP_NUM n){ a.setX(a.getX() + n); }

    void operator+=(Vec &a, Vec &b){ a.Add(b); }

    void operator^=(Vec &a, Vec &b){ a.Cross(b); }

    void operator*=(Vec &a, Vec &b){ a.Mul(a.getDot(b)); }

    void operator-=(Vec &a, TSP_NUM n){ a.setX(a.getX() - n); }

    void operator-=(Vec &a, Vec &b){ a.Sub(b); }

    Vec operator*(TSP_NUM n, Vec &b)
    {
      return Vec(n * b.getX(), n * b.getY(), n * b.getZ());
    }

    Vec operator*(Vec &b, TSP_NUM n)
    {
      return Vec(n * b.getX(), n * b.getY(), n * b.getZ());
    }

    Vec  operator/(Vec &b, TSP_NUM n)
    {
      cVec v = Vec();
      if(n == 0){ v.setNote("%s operator/(vec&,num): Divide by zero",TSP_ERR_COD); return v; }
      v.Set(b.getX() / n, b.getY() / n, b.getZ() / n); return v;
    }

    void operator*=(Vec &a, TSP_NUM n)
    {
      a.Mul(n);
    }

    void operator/=(Vec &a, TSP_NUM n)
    {
      if(n == 0){ a.setNote("%s oerator(/=): Divide by zero",TSP_ERR_COD); return; }
      a.Div(n);
    }

    TSP_BUL operator==(Vec &a, Vec &b)
    {
      return ((a.getX() == b.getX()) &&
              (a.getY() == b.getY()) &&
              (a.getZ() == b.getZ()));
    }

    TSP_BUL operator!=(Vec &a, Vec &b)
    {
      return ((a.getX() != b.getX()) ||
              (a.getY() != b.getY()) ||
              (a.getZ() != b.getZ()));
    }

    TSP_BUL operator>=(Vec &a, Vec &b)
    {
      return (a.getDistance() >= b.getDistance());
    }

    TSP_BUL operator<=(Vec &a, Vec &b)
    {
      return (a.getDistance() <= b.getDistance());
    }

    TSP_BUL operator>(Vec &a, Vec &b)
    {
      return (a.getDistance() > b.getDistance());
    }

    TSP_BUL operator<(Vec &a, Vec &b)
    {
      return (a.getDistance() < b.getDistance());
    }

    Vec operator++(Vec &b, int a)
    {
      cVec dr = b.getDirection();
      b.Add(dr); dr.Sub(b).Neg();
      return dr;
    }

    Vec operator--(Vec &b, int a)
    {
      cVec dr = b.getDirection();
      b.Sub(dr); dr.Add(b);
      return dr;
    }

    Vec& operator++(Vec &b)
    {
      cVec dr = b.getDirection();
      b.Add(dr); return b;
    }

    Vec& operator--(Vec &b)
    {
      cVec dr = b.getDirection();
      b.Sub(dr); return b;
    }

    TSP_NUM Vec::getAngleRad(class Vec *b)
    {
      if(b == NULL){ setNote("%s getAngleRad(vec*): Argument is null",TSP_ERR_COD); return 0; }
      TSP_NUM dot = getDot(b);
      TSP_NUM abd = getDistance();
      TSP_NUM avd = b->getDistance();
      if(abd == 0){ setNote("%s getAngleRad(vec*): Base module is zero",TSP_ERR_COD); return 0; }
      if(avd == 0){ setNote("%s getAngleRad(vec*): Argument module is zero",TSP_ERR_COD); return 0; }
      return acos(dot / ( abd * avd ));
    }

    TSP_NUM Vec::getAngleRad(class Vec &b)
    {
      TSP_NUM dot = getDot(&b);
      TSP_NUM abd = getDistance();
      TSP_NUM avd = b.getDistance();
      if(abd == 0){ setNote("%s getAngleRad(vec*): Base module is zero",TSP_ERR_COD); return 0; }
      if(avd == 0){ setNote("%s getAngleRad(vec*): Argument module is zero",TSP_ERR_COD); return 0; }
      return acos(dot / ( abd * avd ));
    }

    TSP_NUM Vec::getAngleDeg(class Vec &b)
    {
      return ( getAngleRad(&b) * ( 180 / TSP_PI));
    }

    TSP_NUM Vec::getAngleDeg(class Vec *b)
    {
      if(b == NULL){ setNote("%s getAngleDeg(vec*): Argument is null",TSP_ERR_COD); return 0; }
      return ( getAngleRad(b) * ( 180 / TSP_PI));
    }

    Vec& Vec::Project(class Vec *b)
    {
      if(b == NULL){ setNote("%s getAngleDeg(vec*): Argument is null",TSP_ERR_COD); return *this; }
      TSP_NUM bcx = b->getX();
      TSP_NUM bcy = b->getY();
      TSP_NUM bcz = b->getZ();
      TSP_NUM dst2 = bcx*bcx + bcy*bcy + bcz*bcz;
      if(dst2 == 0){ setNote("%s Project(vec*): Argument module is zero",TSP_ERR_COD); return *this; }
      TSP_NUM dot = getDot(b) / dst2;
      Set(dot*bcx, dot*bcy, dot*bcz);
      return *this;
    }

    Vec& Vec::Project(class Vec &b)
    {
      TSP_NUM bcx = b.getX();
      TSP_NUM bcy = b.getY();
      TSP_NUM bcz = b.getZ();
      TSP_NUM dst2 = bcx*bcx + bcy*bcy + bcz*bcz;
      if(dst2 == 0){ setNote("%s Project(vec&): Argument module is zero",TSP_ERR_COD); return *this; }
      TSP_NUM dot = getDot(b) / dst2;
      Set(dot*bcx, dot*bcy, dot*bcz);
      return *this;
    }

    Vec Vec::getProject(class Vec *b)
    {
      cVec v = Vec();
      if(b == NULL){ v.setNote("%s getProject(vec*): Argument is null",TSP_ERR_COD); return v;}
      TSP_NUM bcx = b->getX();
      TSP_NUM bcy = b->getY();
      TSP_NUM bcz = b->getZ();
      TSP_NUM dst2 = bcx*bcx + bcy*bcy + bcz*bcz;
      if(dst2 == 0){ v.setNote("%s getProject(vec*): Argument module is zero",TSP_ERR_COD); return v; }
      TSP_NUM dot = getDot(b) / dst2; v.Set(dot*bcx, dot*bcy, dot*bcz); return v;
    }

    Vec Vec::getProject(class Vec &b)
    {
      cVec v = Vec();
      TSP_NUM bcx = b.getX();
      TSP_NUM bcy = b.getY();
      TSP_NUM bcz = b.getZ();
      TSP_NUM dst2 = bcx*bcx + bcy*bcy + bcz*bcz;
      if(dst2 == 0){ v.setNote("%s getProject(vec&): Argument module is zero",TSP_ERR_COD); return v; }
      TSP_NUM dot = getDot(b) / dst2; v.Set(dot*bcx, dot*bcy, dot*bcz); return v;
    }

    Vec& Vec::Cross(class Vec *b)
    {
      if(b == NULL){ setNote("s Cross(vec*): Argument is null",TSP_ERR_COD); return *this; }
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
      cVec v = Vec();
      if(b == NULL){ v.setNote("%s getCross(vec*): Argument is null",TSP_ERR_COD); return v; }
      v.Set(this).Cross(b); return v;
    }

    Vec Vec::getCross(class Vec &b)
    {
      cVec v = Vec(); v.Set(this).Cross(b); return v;
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
      if(b == NULL){ setNote("%s CrossTriple(vec*, vec*): First argument module is null" ,TSP_ERR_COD); return *this; }
      if(c == NULL){ setNote("%s CrossTriple(vec*, vec*): Second argument module is null",TSP_ERR_COD); return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b->getX()) - (ab * c->getX()),
          (ac * b->getY()) - (ab * c->getY()),
          (ac * b->getZ()) - (ab * c->getZ()));
      return *this;
    }
    Vec& Vec::CrossTriple(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setNote("%s CrossTriple(vec&): First argument is null",TSP_ERR_COD); return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b->getX()) - (ab * c.getX()),
          (ac * b->getY()) - (ab * c.getY()),
          (ac * b->getZ()) - (ab * c.getZ()));
      return *this;
    }

    Vec& Vec::CrossTriple(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setNote("%s CrossTriple(vec&): Second argument is null",TSP_ERR_COD); return *this; }
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
      cVec v = Vec();
      if(b == NULL){ v.setNote("%s getCrossTriple(vec*,vec*): First argument is null" ,TSP_ERR_COD); return v; }
      if(c == NULL){ v.setNote("%s getCrossTriple(vec*,vec*): Second argument is null",TSP_ERR_COD); return v; }
      v.Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec *b, class Vec &c)
    {
      cVec v = Vec();
      if(b == NULL){ v.setNote("%s getCrossTriple(vec*,vec&): First argument is null",TSP_ERR_COD); return v; }
      v.Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec &b, class Vec *c)
    {
      cVec v = Vec();
      if(c == NULL){ v.setNote("%s getCrossTriple(vec&,vec*): Second argument is null",TSP_ERR_COD); return v; }
      v.Set(this).CrossTriple(b,c); return v;
    }

    TSP_NUM Vec::getDot(class Vec *b)
    {
      if(b == NULL){ setNote("%s getDot(vec*): Argument is null",TSP_ERR_COD); return 0; }
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
      if(b == NULL){ setNote("%s Add(vec*): Argument is null",TSP_ERR_COD); return *this; }
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
      cVec v = Vec();
      if(b == NULL){ v.setNote("%s getAdd(vec*): Argument is null",TSP_ERR_COD); return v; }
      v.Set(this).Add(b); return v;
    }

    Vec Vec::getAdd(class Vec &b)
    {
      cVec v = Vec().Set(this).Add(b); return v;
    }

    Vec& Vec::Sub(class Vec *b)
    {
      if(b == NULL){ setNote("%s Sub(vec*): Argument is null",TSP_ERR_COD); return *this; }
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
      cVec v = Vec();
      if(b == NULL){ v.setNote("%s getSub(vec*): Argument is null",TSP_ERR_COD); return v; }
      v.Set(this).Sub(b); return v;
    }

    Vec Vec::getSub(class Vec &b)
    {
      cVec v = Vec().Set(this).Sub(b); return v;
    }

    Vec& Vec::Set(class Vec *b)
    {
      if(b == NULL){ setNote("%s Set(vec*): Argument is null",TSP_ERR_COD); return *this; }
      setX(b->getX()); setY(b->getY()); setZ(b->getZ()); return *this;
    }

    Vec& Vec::Set(class Vec &b)
    {
      setX(b.getX()); setY(b.getY()); setZ(b.getZ()); return *this;
    }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x); setY(y); setZ(z); return *this;
    }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y)
    {
      setX(x); setY(y); setZ(0); return *this;
    }

    Vec& Vec::Set(TSP_NUM x)
    {
      setX(x); setY(0); setZ(0); return *this;
    }

    Vec& Vec::Set(void)
    {
      setX(0); setY(0); setZ(0); return *this;
    }

    TSP_NUM Vec::getCosine(TSP_STR ax)
    {
      TSP_NUM ab = getDistance();
      if(ab ==  0 ){ setNote("%s getCrossTriple(str): Base module is zero",TSP_ERR_COD); return 0; }
      if(ax == 'x'){ return getX() / ab; }
      if(ax == 'y'){ return getY() / ab; }
      if(ax == 'z'){ return getZ() / ab; }
      return 0;
    }

    Vec& Vec::Mul(TSP_NUM n)
    {
      setX(getX() * n); setY(getY() * n); setZ(getZ() * n); return *this;
    }

    Vec Vec::getMul(TSP_NUM n)
    {
      cVec v = Vec().Set(this).Mul(n); return v;
    }

    Vec& Vec::Div(TSP_NUM n)
    {
      if(n == 0){ setNote("%s Div(num): Divide by zero",TSP_ERR_COD); return *this; }
      setX(getX() / n); setY(getY() / n); setZ(getZ() / n); return *this;
    }

    Vec Vec::getDiv(TSP_NUM n)
    {
      cVec v = Vec();
      if(n == 0){ v.setNote("%s getDiv(num): Divide by zero",TSP_ERR_COD); return v; }
      v.Set(this).Div(n); return v;
    }
    Vec Vec::getRound(void)
    {
      cVec v = Vec();
      v.Set(this).Round();
      return v;
    }

    Vec Vec::getTrunc(void)
    {
      cVec v = Vec();
      v.Set(this).Trunc();
      return v;
    }

    Vec Vec::getFloor(void)
    {
      cVec v = Vec();
      v.Set(this).Floor();
      return v;
    }

    Vec Vec::getCeil(void)
    {
      cVec v = Vec();
      v.Set(this).Ceil();
      return v;
    }

    Vec& Vec::RoundDigit(unsigned int d)
    {
      TSP_NUM mul = pow(10,d);
      Mul(mul); Round(); Div(mul);
      return *this;
    }

    Vec Vec::getRoundDigit(unsigned int d)
    {
      cVec v = Vec();
      v.Set(this).RoundDigit(d);
      return v;
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec *b)
    {
      if(b == NULL){ setNote("%s getAreaParallelogram(vec*): Argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec &b)
    {
      return TSP_ABS(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaTriangle(class Vec *b)
    {
      if(b == NULL){ setNote("%s getAreaTriangle(vec*): Argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getAreaTriangle(class Vec &b)
    {
      return TSP_ABS(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getMixed(class Vec &b, class Vec &c)
    {
      cVec v = b.getCross(c); return getDot(v);
    }

    TSP_NUM Vec::getMixed(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setNote("%s getMixed(vec*,vec*): First argument is null" ,TSP_ERR_COD); return 0; }
      if(c == NULL){ setNote("%s getMixed(vec*,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      cVec v = b->getCross(c);
      return getDot(v);
    }

    TSP_NUM Vec::getMixed(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setNote("%s getMixed(vec*,vec&): First argument is null",TSP_ERR_COD); return 0; }
      cVec v = b->getCross(c);
      return getDot(v);
    }

    TSP_NUM Vec::getMixed(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setNote("%s getMixed(vec&,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      cVec v = b.getCross(c);
      return getDot(v);
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec &b, class Vec &c)
    {
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setNote("%s getVolumeParallelepiped(vec*,vec*): First argument is null" ,TSP_ERR_COD); return 0; }
      if(c == NULL){ setNote("%s getVolumeParallelepiped(vec*,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setNote("%s getVolumeParallelepiped(vec*,vec&): First argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setNote("%s getVolumeParallelepiped(vec&,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &b, class Vec &c)
    {
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setNote("%s getVolumeTetrahedron(vec*,vec*): First argument is null" ,TSP_ERR_COD); return 0; }
      if(c == NULL){ setNote("%s getVolumeTetrahedron(vec*,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setNote("%s getVolumeTetrahedron(vec*,vec&): First argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setNote("%s getVolumeTetrahedron(vec&,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_BUL Vec::isCoplanar(class Vec &a, class Vec &b)
    {
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(class Vec *a, class Vec *b)
    {
      if(a == NULL){ setNote("%s isCoplanar(vec*,vec*): First argument is null" ,TSP_ERR_COD); return 0; }
      if(b == NULL){ setNote("%s isCoplanar(vec*,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(class Vec &a, class Vec *b)
    {
      if(b == NULL){ setNote("%s isCoplanar(vec&,vec*): Second argument is null",TSP_ERR_COD); return 0; }
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(class Vec *a, class Vec &b)
    {
      if(a == NULL){ setNote("%s isCoplanar(vec*,vec&): First argument is null",TSP_ERR_COD); return 0; }
      return (getMixed(a,b) == 0);
    }

    Vec& Vec::Offset(class Vec *d, TSP_NUM n)
    {
      if(d == NULL){ setNote("%s Offset(dir*,num): Direction is null",TSP_ERR_COD); return *this; }
      cVec dir = d->getDirection();
           dir.Mul(n);
      setX(getX() + dir.getX());
      setY(getY() + dir.getY());
      setZ(getZ() + dir.getZ());
      return *this;
    }

    Vec& Vec::Offset(class Vec &d, TSP_NUM n)
    {
      cVec dir = d.getDirection();
           dir.Mul(n);
      setX(getX() + dir.getX());
      setY(getY() + dir.getY());
      setZ(getZ() + dir.getZ());
      return *this;
    }

    Vec Vec::getOffset(class Vec *d, TSP_NUM n)
    {
      cVec v = Vec();
      if(d == NULL){ v.setNote("%s getOffset(dir*,num): Direction is null",TSP_ERR_COD); return v; }
      v.Set(this).Offset(d,n); return v;
    }

    Vec Vec::getOffset(class Vec &d, TSP_NUM n)
    {
      cVec v = Vec().Set(this).Offset(d,n); return v;
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

    Vec& Vec::Swap(const void* cmp)
    {
      TSP_NUM T      = 0.0;
      TSP_STR swp[2] = {0};
      const TSP_STR *cms = (const TSP_STR*)cmp;
      swp[0] = cms[0] | 0x20;
      swp[1] = cms[1] | 0x20;
      if     (!memcmp(swp,"xy",2) || !memcmp(swp,"yx",2)){ T = X; X = Y; Y = T; }
      else if(!memcmp(swp,"yz",2) || !memcmp(swp,"zy",2)){ T = Y; Y = Z; Z = T; }
      else if(!memcmp(swp,"zx",2) || !memcmp(swp,"xz",2)){ T = Y; Y = Z; Z = T; }
      else setNote("%s Swap(str*): Wrong components <%c%c>",TSP_ERR_COD,swp[0],swp[1]);
      return *this;
    }

    Vec Vec::getSwap(const void* cmp)
    {
      cVec v = Vec(); v.Set(this).Swap(cmp); return v;
    }
#endif
