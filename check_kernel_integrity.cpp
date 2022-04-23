__int64 be::check_kernel_integrity()
{
  __int64 result; // rax
  char *kernel; // rbx
  char *v2; // rax
  char *v3; // rax
  _QWORD *v4; // r15
  __int64 v5; // r12
  unsigned __int64 *v6; // rbx
  unsigned __int64 v7; // rsi
  unsigned __int64 i; // rbx
  unsigned __int64 v9; // rcx
  __int64 v10; // r8
  __int64 v11; // rax
  __int64 v12; // rdi
  __int64 v13; // r10
  __int64 v14; // rax
  __int64 v15; // rdx
  __int64 v16; // r10
  _DWORD *OptionalHeader; // rdx
  int v18; // er9
  unsigned int v19; // er8
  unsigned int v20; // ecx
  _BYTE *v21; // rdi
  unsigned __int64 *v22; // r14
  unsigned __int64 v23; // rdx
  __int64 j; // rbx
  __int64 v25; // [rsp+20h] [rbp-89h]
  __int64 v26; // [rsp+28h] [rbp-81h]
  unsigned int AddressOfEntryPoint; // [rsp+50h] [rbp-59h] BYREF
  __int64 v28; // [rsp+58h] [rbp-51h] BYREF
  char v29[16]; // [rsp+60h] [rbp-49h] BYREF
  char v30[16]; // [rsp+70h] [rbp-39h] BYREF
  char v31[16]; // [rsp+80h] [rbp-29h] BYREF
  int v32; // [rsp+90h] [rbp-19h] BYREF
  __int64 v33; // [rsp+98h] [rbp-11h]
  char *v34; // [rsp+A0h] [rbp-9h]
  int v35; // [rsp+A8h] [rbp-1h]
  __int128 v36; // [rsp+B0h] [rbp+7h]
  int v37; // [rsp+C0h] [rbp+17h] BYREF
  char v38; // [rsp+C4h] [rbp+1Bh]
  char v39[8]; // [rsp+C8h] [rbp+1Fh] BYREF
  char v40[8]; // [rsp+D0h] [rbp+27h] BYREF
  char v41[8]; // [rsp+D8h] [rbp+2Fh] BYREF

  result = 11362i64;
  if ( (unsigned __int16)(*(_WORD *)NtBuildNumber_0 - 7600) <= 0x2C62u )
  {
    if ( (int)sub_140344C24(1) >= 0
      || (result = sub_140344C24(0), (int)result >= 0) && (result = sub_140344C24(1), (int)result >= 0) )
    {
      kernel = 0i64;
      KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
      if ( qword_140016830 )
        kernel = *(char **)(qword_140016830 + 0x508);
      result = KeReleaseMutex(0x1400161D8i64, 0i64);
      if ( kernel )
      {
        strcpy(v39, ".data");
        v2 = get_pe_section(kernel, (__int64)v39, &AddressOfEntryPoint);
        v37 = 0x3804082C;
        v38 = 0xC;
        if ( v2 )
        {
          result = (__int64)sub_14034B2FF((__int64)v2, AddressOfEntryPoint, (__int64)&v37, 5ui64);
          if ( result )
            goto LABEL_57;
        }
        if ( (strcpy(v41, ".rdata"), (v3 = get_pe_section(kernel, (__int64)v41, &AddressOfEntryPoint)) != 0i64)
          && (result = (__int64)sub_14034B2FF((__int64)v3, AddressOfEntryPoint, (__int64)&v37, 5ui64)) != 0
          || (strcpy(v40, ".text"), (result = (__int64)get_pe_section(kernel, (__int64)v40, &AddressOfEntryPoint)) != 0)
          && (result = (__int64)sub_14034B2FF(result, AddressOfEntryPoint, (__int64)&v37, 5ui64)) != 0 )
        {
LABEL_57:
          v4 = *(_QWORD **)(result + 14);
          result = MmIsAddressValid(v4);
          if ( (_BYTE)result )
          {
            v5 = 3i64;
            do
            {
              if ( *v4 >= 0xFFFF000000000000ui64 )
              {
                v6 = (unsigned __int64 *)(*v4
                                        + (-(__int64)(*(_WORD *)NtBuildNumber_0 > 0x23F0u) & 0xFFFFFFFFFFFFFFF0ui64)
                                        + 0x28);
                result = MmIsAddressValid(v6);
                if ( (_BYTE)result )
                {
                  v7 = *v6;
                  KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
                  for ( i = qword_140016828; ; i = *(_QWORD *)(i + 1320) )
                  {
                    if ( !i )
                      goto LABEL_54;
                    v9 = *(_QWORD *)(i + 1288);
                    if ( v7 >= v9 && v7 < *(unsigned int *)(i + 1296) + v9 )
                      break;
                  }
                  RtlInitAnsiString(v30, i + 2);
                  LOBYTE(v10) = 1;
                  if ( (int)RtlAnsiStringToUnicodeString(v29, v30, v10) < 0 )
                  {
LABEL_54:
                    result = KeReleaseMutex(0x1400161D8i64, 0i64);
                    goto LABEL_35;
                  }
                  v33 = 0i64;
                  LODWORD(v26) = 32;
                  LODWORD(v25) = 7;
                  v35 = 576;
                  v32 = 48;
                  v34 = v29;
                  v36 = 0i64;
                  if ( (int)ZwOpenFile(&v28, 0x80000000i64, &v32, v31, v25, v26) >= 0 )
                  {
                    v11 = ExAllocatePool(1i64, 0x1000i64);
                    v12 = v11;
                    if ( v11 )
                    {
                      if ( (int)ZwReadFile(v28, 0i64, 0i64, 0i64, v31, v11, 4096, 0i64, 0i64) >= 0
                        && *(_DWORD *)(v12 + 0x3C) <= 0xFF8u )
                      {
                        _mm_lfence();
                        v13 = *(unsigned int *)(v12 + 0x3C);
                        v14 = *(unsigned __int16 *)(v13 + v12 + 20);
                        v15 = v13 + 24;
                        v16 = *(unsigned __int16 *)(v13 + v12 + 6);
                        OptionalHeader = (_DWORD *)(v14 + v12 + v15);
                        if ( (unsigned __int64)OptionalHeader + 40 * v16 - v12 <= 0x1000 )
                        {
                          v18 = 0;
                          v19 = v7 - *(_DWORD *)(i + 0x508);
                          if ( (_DWORD)v16 )
                          {
                            while ( 1 )
                            {
                              v20 = OptionalHeader[3];
                              if ( v19 >= v20 && v19 < OptionalHeader[2] + v20 )
                                break;
                              OptionalHeader += 10;
                              if ( ++v18 >= (unsigned int)v16 )
                                goto LABEL_33;
                            }
                            if ( (OptionalHeader[9] & 0x22000000) != 0x20000000 )
                              i = 1i64;
                          }
                        }
                      }
LABEL_33:
                      ExFreePoolWithTag(v12, 0i64);
                      ZwClose(v28);
                    }
                    else
                    {
                      ZwClose(v28);
                    }
                  }

                  RtlFreeUnicodeString(v29);
                  result = KeReleaseMutex(0x1400161D8i64, 0i64);
LABEL_35:
                  if ( i <= 1 && v7 >= 0xFFFF000000000000ui64 )
                  {
                    result = ExAllocatePool(512i64, 73i64);
                    v21 = (_BYTE *)result;
                    if ( result )
                    {
                      v22 = (unsigned __int64 *)(result + 1);
                      v23 = v7;
                      if ( i )
                        v23 = v7;
                      *v22 = v23;
                      if ( (int)sub_14034D2BA(v7, result + 9, 64i64) < 0 )
                        memset(v21 + 9, 0, 0x40ui64);
                      for ( j = qword_140016868; ; j = *(_QWORD *)(j + 16) )
                      {
                        if ( !j )
                        {
                          *v21 = 23;
                          be::report((__int64)v21, 0x49i64);
                          be::report_custom_list((unsigned __int64)v22, 72i64, &qword_140016868, 0x140016870i64);
                          result = ExFreePoolWithTag(v21, 0i64);
                          goto LABEL_45;
                        }
                        if ( !(unsigned int)sub_140013A60(*(unsigned __int64 **)j, (__int64)v22, 0x48ui64) )
                          break;
                      }
                      result = ExFreePoolWithTag(v21, 0i64);
                    }
                  }
                }
              }
LABEL_45:
              ++v4;
              --v5;
            }
            while ( v5 );
          }
        }
      }
    }
  }
  return result;
}