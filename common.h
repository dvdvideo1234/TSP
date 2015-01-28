#ifndef COMMON_H_
    #include "mytypes.h"
    #define COMMON_H_

    void PrintArrCol(void* Arr, u32 Len, const char *Info)
    {
        u32 i;
        u8* Data = (u8*)Arr;
        printf("\r\n");
        printf("%s\n",Info);
        for(i=0;i<Len;i++)
            printf("Ind: %8u -> %3u, %02x, %c \n",i,Data[i],Data[i],Data[i]);
    }

    void PrintArrLine(void* Arr, u32 Len, const char *Info)
    {
        u32 i;
        u8* Data = (u8*)Arr;
        printf("\r\n");
        printf("%s\n",Info);
        for(i=0;i<Len;i++)
            printf("%6u,",Data[i]);
        printf("\n");
    }

    void PrintArrHEX2File(FILE *F, u8* Arr, u8 Cols)
    {
      u8 Cnt = Cols;
      if(NULL != F)
      {
        fprintf(F,"\nArrPrintHEX2File: Writing!\n");
        while(*Arr != '\0')
        {
          if(--Cnt)
          {
            fprintf(F,"0x%02x ",*Arr);
          }else{
            Cnt = Cols;
            fprintf(F,"0x%02x ",*Arr);
            fprintf(F,"\n");
          }
          Arr++;
        }
        fprintf(F,"\n");
      }else{ printf("\nArrPrintHEX2File: There is no file!\n"); }
    }

    template <class AbsType>
    AbsType Abs(AbsType Data)
    {
        if(Data < 0){ return -Data; }
        return Data;
    }

    void AdrByteMirror(void* Byte)
    {
        u8* B = (u8*)Byte;
        u8 Cnt = 8;
        u8 Tmp = 0x00;
        while(Cnt--)
        {
            Tmp <<= 1;
            Tmp |= (*B & 0x01);
            *B  >>= 1;
        }
        *B = Tmp;
    }

    void AdrArrMirror(void* Adr, s32 BytesCnt)
    {
        u8 *S, *E;
        u8 Tmp, Swap;

        if(BytesCnt < 0){ Swap = 0xFF; }
        else            { Swap = 0x00; }

        BytesCnt = Abs<s32>(BytesCnt);

        if(NULL != Adr)
        {
            S = (u8*)Adr;
            E = (u8*)Adr;
            E = &E[BytesCnt-1];
            printf("\nDiff: %d",E-S);
            while(S < E)
            {
                AdrByteMirror(S);
                AdrByteMirror(E);
                if(Swap)
                {
                    Tmp = *S;
                    *S  = *E;
                    *E  = Tmp;
                }
                S++;
                E--;
            }
            if(S == E)
            {
                AdrByteMirror(E);
            }
        }
    }

    u8 CharExistInCppStr(s8 Ch, const s8* Str, u32 *Index)
    {
        *Index = 0;
        while(Str[*Index] != '\0')
        {
            if(Ch == Str[*Index])
            {
                return 0xFF;
            }
            (*Index)++;
        }
        return 0x00;
    }

    s8 CharToggleCapitalizeLatin(s8 Ch)
    {
        return (Ch ^ 32);
    }

    u8 CharIsVisible(u8 Ch)
    {
        if((Ch > 0x20) && (Ch < 0x7F)) return 0xFF;
        return 0x00;
    }
    s8 CharIsSmallLatinLetter(s8 Ch)
    {
        if((Ch >= 'a') && (Ch <= 'z')) return 0xFF;
        return 0x00;
    }
    s8 CharIsLatinLetter(s8 Ch)
    {
        if(((Ch >= 'a') && (Ch <= 'z')) ||
           ((Ch >= 'A') && (Ch <= 'Z'))){ return 0xFF; }
        return 0x00;
    }
    void StrCppCapitalizeLatin(s8* Str)
    {
        u32 i = 0;
        while(Str[i] != '\0')
        {
            if(CharIsSmallLatinLetter(Str[i]))
                Str[i] = CharToggleCapitalizeLatin(Str[i]);
        }
    }

    void StrCppRemoveChars(s8 *S, const s8* Chars)
    {
        u32 Whr = 0;
        u32 Jmp = 0;
        u32 Ind = 0;
        while(S[Ind+Jmp] != '\0')
        {
            if(CharExistInCppStr(S[Ind+Jmp],Chars,&Whr))
            {
                Jmp++;
            }else{
                S[Ind] = S[Ind+Jmp];
                Ind++;
            }
        }
        S[Ind] = '\0';
    }

    u8 StrCppEndsLike(s8* S, const s8* E)
    {
        u32 i = 0, j = 0;
        while(E[i] != '\0'){ i++; }
        while(S[j] != '\0'){ j++; }
        while(i+1)
        {
            if(S[j] != E[i]) return 0x00;
            i--;
            j--;
        }
        return 0xFF;
    }

    f32 RootCast(f32 x)
    {
      u32 i = *(u32*) &x;
      i  += 127 << 23;
      i >>= 1;
      return *(f32*) &i;
    }

    f32 RootIter(f32 v, f32 p, u32 i)
    {
        f32 l = 0;
        f32 h = v;
        f32 m = l + (h - l) / 2;
        if(h < 0) return -1;
        if(h == 0) return 0;
        while((((h - l) > p)) && i--)
        {
            m = l + (h - l) / 2;
            if((m * m - v) > p)
            {
                h = m;
            }else
                l = m;
            }
        return m;
    }

    u16 BytesU16(u8 *Data)
    {
       u16 Rez = 0;
       Rez |= Data[0]; Rez = Rez << 8;
       Rez |= Data[1];
       return Rez;
    }
    void U16Bytes(u16 Data, u8 *Adr)
    {
       Adr[0] = (u8)(Data >> 8);
       Adr[1] = (u8)(Data);
    }

    u32 BytesU32(u8* Data)
    {
        u32 Rez = 0;
        Rez |= Data[0]; Rez = Rez << 8;
        Rez |= Data[1]; Rez = Rez << 8;
        Rez |= Data[2]; Rez = Rez << 8;
        Rez |= Data[3];
        return Rez;
    }

    void U32Bytes(u32 Data, u8* Adr)
    {
        Adr[0] = (u8)((Data & 0xFF000000) >> 24);
        Adr[1] = (u8)((Data & 0x00FF0000) >> 16);
        Adr[2] = (u8)((Data & 0x0000FF00) >> 8);
        Adr[3] = (u8)Data;
    }

    void StrPascalCpy(u8* D, u8* S)
    {
        u32 s,d,k;
        s = BytesU32(&S[0]);
        d = BytesU32(&D[0]);
        if(d >= s) k = s;
        if(d <= s) k = d;
        s = k + 4;
        d = k;
        k = 4;
        while(k < s)
        {
            D[k] = S[k];
            k++;
        }
        U32Bytes(d,&D[0]);
    }

    void StrPascalPrint(u8* Str)
    {
        u32 i = BytesU32(&Str[0]);
        u32 n = i;
        while(i) printf("%c",Str[n-i--+4]);
    }

    u32 StrPascalLen(u8* Str)
    {
        return BytesU32(&Str[0]);
    }

    u8 StrPascalLike(u8* Str, u8* Like)
    {
        u32 s = StrPascalLen(Str) + 4;
        u32 l = StrPascalLen(Like)+ 4;
        if(s >= l) s = l;
        l = 4;
        while(l < s)
        {
            if(Str[l] != Like[l])
            {
               return 0x00;
            }
            l++;
        }
        return 0xFF;
    }

    u8* StrCpp2Pascal(u8* Cpp)
    {
        u32 Len = 0;
        u32 Cnt = 0;
        u8* Out = NULL;
        while(Cpp[Len] != '\0') Len++;
        Out = (u8*)malloc((Len+4)*sizeof(u8));
        if(Out != NULL)
        {
            U32Bytes(Len,&Out[0]);
            while(Cnt < Len)
            {
                Out[Cnt+4] = Cpp[Cnt];
                Cnt++;
            }
            return Out;
        }
        return NULL;
    }

    u8* StrPascal2Cpp(u8* S)
    {
        u32  i = 0;
        u32  L = BytesU32(&S[0])+1;
        u8 *Out = (u8*)malloc(L*sizeof(u8));
        if(Out == NULL) return NULL;
        for(i=0;i<L;i++)
            Out[i] = S[i+4];
        Out[L-1] = '\0';
        return Out;
    }
    void Delay(u32 Len)
    {
        while(Len--);
    }

    void StrCppExtendEndChar(s8* Str, s8 Ch, u32 Cnt)
    {
        u32 Cur = 0;
        while(Cur < Cnt)
        {
            Str[Cur++] = Ch;
        }
        Str[Cur] = '\0';
    }

    void StrCppFillChar(s8* Str, s8 Ch, u32 Cnt)
    {
        Str[Cnt-1] = '\0';
        Cnt -= 1;
        while(Cnt--)
        {
            Str[Cnt] = Ch;
        }
    }

    u32 StrCppOverallLen(u8 *Str)
    {
       u32 i=0;
       while(Str[i++] != '\0');
       return i;
    }

    void StrCppSwap(u8* Str, u8* S, u8* E)
    {
        s8  Ch  = 0;
        u32 Len = StrCppOverallLen((u8*)Str);
        if((S < E) && (Str <= S) && (E <= &Str[Len-2]))
        {
            while(S < E)
            {
                Ch  = *S;
                *S  = *E;
                *E  =  Ch;
                 S++;
                 E--;
            }
        }
    }

    void StrCppTrimChar(s8* Str, s8 ch)
    {
        u32 i = 0;
        u32 j = 0;
        while(Str[i] == ch){ i++; };
        while(Str[i] != '\0')
        {
            Str[j] = Str[i];
            i++;
            j++;
        }
        while(Str[j] != '\0')
        {
            Str[j++] = ch;
        }
        j--;
        while(Str[j] == ch){ j--; };
        Str[j+1] = '\0';
    }

    s8 StrCppStartsLike(const s8 *Str, const s8* Like)
    {
       while(*Str == *Like && *Str != '\0' && *Like != '\0')
       {
           Str++;
           Like++;
       }
       return *Like - *Str;
    }

    void DumpNChar(u8 *Str, u32 Len)
    {
        u32 Cnt = 0;
        printf("\n\rDumping The Memory\n\r");
        while(Cnt != Len)
        {
            printf("%c",Str[Cnt]);
            Cnt++;
        }
    }
    void DumpNVal(u8 *Str, u32 Len)
    {
        u32 Cnt = 0;
        printf("\n\rDumping The Memory\n\r");
        while(Cnt != Len)
        {
            printf("%3u,",Str[Cnt]);
            Cnt++;
        }
    }

    void IncArrDecimals(u32 *Arr, u32 Len, u32 Max)
    { // 0 is the Oldest
        while(Len)
        {
            if(Arr[Len-1] == Max)
            {
                Arr[Len-1] = 0;
                Len--;
                continue;
            }else{
                Arr[Len-1]++;
                break;
            }
        }
    }

    void DecArrDecimals(u32 *Arr, u32 Len, u32 Max)
    { // 0 is the Oldest
        while(Len)
        {
            if(Arr[Len-1] == 0)
            {
                Arr[Len-1] = Max;
                Len--;
                continue;
            }else{
                Arr[Len-1]--;
                break;
            }
        }
    }

    u64 Pow(u32 Base, u32 Arg)
    {
        u64 B = (u64)Base;
        u64 A = (u64)Arg;
        u64 Rez = B;
        if(A == 0)
            return 1;
        if(A > 0)
        {
            while(--A)
                Rez *= B;
            return Rez;
        }
        return 0;
    }

    f32 Pi(u32 N)
    {
        u32 C = 1, M = 3;
        s8  S = -1;
        f32 P = 0.0, Val = 1.0;
        if(N > 20){ N = 20; }
        while(C <= N)
        {
            P = Pow(3.0,C);
            Val = Val + ( (f32)S / ((f32)M * P) );
            M += 2;
            S = -S;
            C++;
        }
        return Val * RootIter(12,0.00001,100);
    }

#endif
