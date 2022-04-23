unsigned __int64 __fastcall be::check_flt_filters(__int64 a1)
{
  unsigned __int64 result; // rax
  __int64 v3; // r8
  __int64 v4; // rcx
  unsigned int v5; // edx
  __int64 v6; // rbx
  __int64 v7; // rbx
  int v8; // esi
  char v9; // r15
  __int64 v10; // rdi
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rcx
  __int64 v13; // rdi
  __int64 v14; // rcx
  char v15[8]; // [rsp+30h] [rbp-D0h] BYREF
  int v16; // [rsp+38h] [rbp-C8h] BYREF
  int *v17; // [rsp+40h] [rbp-C0h]
  int v18[18]; // [rsp+48h] [rbp-B8h] BYREF
  char v19[128]; // [rsp+90h] [rbp-70h] BYREF

  result = IoGetTopLevelIrp();
  if ( !result )
  {
    result = ObQueryNameString(a1, v19, 128i64, v15);
    if ( (result & 0x80000000) == 0i64 )
    {
      v18[0] = 0xFFB9FFA3;
      v4 = (__int64)v18;
      v18[1] = 0xFF93FF96;
      v5 = 0;
      v18[2] = 0xFFACFF9A;
      v18[3] = 0xFF8CFF86;
      v18[4] = 0xFF9AFF8B;
      v18[5] = 0xFFA3FF92;
      v18[6] = 0xFF96FFB9;
      v18[7] = 0xFF8BFF93;
      v18[8] = 0xFF8DFF9A;
      v18[9] = 0xFFA3FF8C;
      v18[10] = 0xFF93FFB9;
      v18[11] = 0xFFB2FF8B;
      v18[12] = 0xFF8DFF98;
      v18[13] = 0xFF8CFFB2;
      v18[14] = 0xFFFFFF98;
      do
      {
        ++v5;
        *(_WORD *)v4 = ~*(_WORD *)v4;
        v4 += 2i64;
      }
      while ( v5 < 30 );
      v16 = 0x3C003A;
      LOBYTE(v3) = 1;
      v17 = v18;
      result = RtlCompareUnicodeString(v19, &v16, v3);// \FileSystem\Filters\FltMgrMsg
      if ( !(_DWORD)result )
      {
        if ( *(_QWORD *)(a1 + 32) )
        {
          _mm_lfence();
          result = *(_QWORD *)(a1 + 32);
          v6 = *(_QWORD *)(result + 8);
          if ( v6 )
          {
            result = MmIsAddressValid(*(_QWORD *)(result + 8));
            if ( (_BYTE)result )
            {
              v7 = *(_QWORD *)(v6 + 16);
              if ( v7 )
              {
                result = MmIsAddressValid(v7);
                if ( (_BYTE)result )
                {
                  v8 = 0;
                  while ( 1 )
                  {
                    if ( !*(_QWORD *)(v7 + 8i64 * v8 + 16) )
                      goto LABEL_25;
                    v9 = 0;
                    KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
                    v10 = qword_140016828;
                    if ( qword_140016828 )
                    {
                      v11 = *(_QWORD *)(v7 + 8i64 * v8 + 16);
                      while ( 1 )
                      {
                        v12 = *(_QWORD *)(v10 + 1288);
                        if ( v11 >= v12 && v11 < *(unsigned int *)(v10 + 1296) + v12 )
                          break;
                        v10 = *(_QWORD *)(v10 + 1320);
                        if ( !v10 )
                          goto LABEL_18;
                      }
                      v9 = 1;
                    }
LABEL_18:
                    result = KeReleaseMutex(0x1400161D8i64, 0i64);
                    if ( v10 || (result = ExAllocatePool(512i64, 74i64), (v13 = result) == 0) )
                    {
                      if ( !v9 )
                        goto LABEL_25;
LABEL_23:
                      result = be::report_hook(*(_QWORD *)(v7 + 8i64 * v8 + 16), 32, v8);
                      if ( (unsigned int)++v8 >= 3 )
                        return result;
                    }
                    else
                    {
                      *(_BYTE *)result = 31;
                      v14 = *(_QWORD *)(v7 + 8i64 * v8 + 16);
                      *(_BYTE *)(result + 1) = v8;
                      *(_QWORD *)(result + 2) = v14;
                      if ( (int)sub_14034D2BA(*(_QWORD *)(v7 + 8i64 * v8 + 16), result + 10, 64i64) < 0 )
                        memset((void *)(v13 + 10), 0, 0x40ui64);
                      else
                        v9 = 1;
                      be::report(v13, 0x4Ai64);
                      result = ExFreePoolWithTag(v13, 0i64);
                      if ( v9 )
                        goto LABEL_23;
LABEL_25:
                      if ( (unsigned int)++v8 >= 3 )
                        return result;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}