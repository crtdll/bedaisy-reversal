__int64 be::system_thread()
{
  unsigned int v0; // eax
  __int128 *v1; // rax
  unsigned __int16 *v2; // rbx
  char v3; // al
  char v4; // si
  __int64 v5; // rdx
  int v6; // ebx
  __int64 v7; // rax
  __int64 v8; // rdi
  int j; // ebx
  __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // rax
  char v13; // al
  char v14; // cl
  char v15; // al
  char v16; // cl
  char v17; // al
  char v18; // cl
  char v19; // al
  char v20; // cl
  char v21; // al
  char v22; // cl
  char v23; // al
  char v24; // cl
  int v26; // eax
  bool v27; // si
  unsigned int i; // edi
  __int64 v29; // rdi
  __int64 v30; // rax
  __int64 v31; // r8
  __int64 v32; // rcx
  _DWORD v33[4]; // [rsp+30h] [rbp-D0h] BYREF
  struct _UNICODE_STRING v34; // [rsp+40h] [rbp-C0h] BYREF
  _QWORD v35[2]; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v36; // [rsp+60h] [rbp-A0h] BYREF
  _QWORD v37[2]; // [rsp+68h] [rbp-98h] BYREF
  char v38[48]; // [rsp+78h] [rbp-88h] BYREF
  __int64 v39; // [rsp+A8h] [rbp-58h] BYREF
  char v40[16]; // [rsp+B0h] [rbp-50h] BYREF
  char v41[11]; // [rsp+C0h] [rbp-40h] BYREF
  int v42; // [rsp+CBh] [rbp-35h]
  _WORD v43[8]; // [rsp+CFh] [rbp-31h] BYREF
  int v44; // [rsp+E4h] [rbp-1Ch]
  char v45[8]; // [rsp+E8h] [rbp-18h] BYREF
  int v46; // [rsp+F2h] [rbp-Eh]
  __int64 v47; // [rsp+F6h] [rbp-Ah]
  int v48; // [rsp+FEh] [rbp-2h]
  char v49[8]; // [rsp+102h] [rbp+2h] BYREF
  int v50; // [rsp+10Ch] [rbp+Ch]
  char v51[8]; // [rsp+110h] [rbp+10h] BYREF
  char v52[17]; // [rsp+11Bh] [rbp+1Bh] BYREF
  int v53[8]; // [rsp+140h] [rbp+40h] BYREF
  __int16 v54; // [rsp+160h] [rbp+60h]
  int v55[12]; // [rsp+168h] [rbp+68h] BYREF
  __int16 v56; // [rsp+198h] [rbp+98h]
  int v57[12]; // [rsp+1A0h] [rbp+A0h] BYREF
  __int16 v58; // [rsp+1D0h] [rbp+D0h]
  __m128i v59; // [rsp+1D8h] [rbp+D8h] BYREF
  int v60; // [rsp+1E8h] [rbp+E8h]

  be::validate_function_integrity(0, 0i64, (__int128 *)MmGetSystemRoutineAddress);
  v53[0] = 7143501;
  v53[1] = 7536713;
  v53[2] = 6553665;
  v53[3] = 7471204;
  v53[4] = 7536741;
  v53[5] = 5636211;
  v53[6] = 7077985;
  v53[7] = 6553705;
  v54 = 0;
  *(_DWORD *)&v34.Length = 2228256;
  v34.Buffer = (PWSTR)v53;
  be::validate_function_integrity(1, &v34, (__int128 *)MmIsAddressValid);
  v34.Buffer = (PWSTR)v55;
  *(_DWORD *)&v34.Length = 3276848;
  v55[0] = 7798874;
  v56 = 0;
  v55[11] = 7209071;
  v55[10] = 6881396;
  v55[9] = 6357101;
  v55[8] = 7471215;
  v55[7] = 6684782;
  v55[6] = 4784237;
  v55[5] = 6619252;
  v55[4] = 7536761;
  v55[3] = 5439609;
  v55[2] = 7471205;
  v55[1] = 7667793;
  be::validate_function_integrity(2, &v34, (__int128 *)ZwQuerySystemInformation);
  *(_DWORD *)&v34.Length = 3276848;
  v34.Buffer = (PWSTR)v57;
  v57[0] = 0x74004E;
  v58 = 0;
  v57[11] = 0x6E006F;
  v57[10] = 0x690074;
  v57[9] = 0x61006D;
  v57[7] = 0x66006E;
  v57[5] = 0x650074;
  v57[4] = 0x730079;
  v57[2] = 0x720065;
  v57[1] = 0x750051;
  v57[3] = 0x530079;
  v57[6] = 0x49006D;
  v57[8] = 0x72006F;
  be::validate_function_integrity(3, &v34, 0i64);
  v59 = _mm_load_si128((const __m128i *)&xmmword_140014090);
  v60 = 7959151;
  v0 = sub_140346948((__int64)&v59);
  v1 = (__int128 *)j_GetKeServiceDescriptorTable(v0);
  if ( v1 )
    be::validate_function_integrity(4, 0i64, v1);
  be::check_kernel_integrity();
  v2 = (unsigned __int16 *)qword_140016828;
  strcpy((char *)&v39, "win32k");
  strcpy(v41, "hal.dll");
  v42 = 1818427392;
  strcpy((char *)v43, "ipsp.sys");
  *(_DWORD *)&v43[5] = 776553216;
  strcpy((char *)&v43[7], "dll");
  v44 = 1946157056;
  strcpy(v45, "pm.sys");
  v46 = 1936392192;
  v47 = 1937339182i64;
  v48 = 1660944384;
  strcpy(v49, "dd.dll");
  v50 = 1398013952;
  strcpy(v51, "DDD.dll");
  strcpy(v52, "spsys.sys");
  strcpy(&v52[13], "atikmpag.sys");
  strcpy(v40, "csrss.exe");
  while ( v2 )
  {
    v26 = qword_140016268((char *)v2 + *v2 + 2, &v39, 6i64);
    v27 = v26 == 0;
    if ( !v26 )
      goto LABEL_62;
    for ( i = 0; i < 9; ++i )
    {
      if ( !(unsigned int)strcmp((char *)v2 + *v2 + 2, &v41[13 * i]) )
        break;
    }
    if ( i != 9 )
    {
LABEL_62:
      if ( !v27 )
        goto LABEL_73;
    }
    v29 = 0i64;
    if ( v27 )
    {
      v30 = sub_1403440C2(v40, 0i64);
      v29 = v30;
      if ( !v30 )
        goto LABEL_73;
      KeStackAttachProcess(v30, v38);
      if ( v2 != (unsigned __int16 *)qword_140016830 )
        goto LABEL_66;
LABEL_76:
      v32 = *((_QWORD *)v2 + 161);
      if ( !v32 )
        goto LABEL_74;
LABEL_71:
      sub_14034AA45(v32, (__int64)v2 + *v2 + 2);
      if ( v27 )
        goto LABEL_72;
LABEL_73:
      v2 = (unsigned __int16 *)*((_QWORD *)v2 + 165);
    }
    else
    {
      if ( v2 == (unsigned __int16 *)qword_140016830 )
        goto LABEL_76;
LABEL_66:
      if ( v27 && *(_WORD *)NtBuildNumber_0 > 0x2800u )
        goto LABEL_76;
      if ( !*((_BYTE *)v2 + 2) )
        goto LABEL_76;
      RtlInitAnsiString(v37, v2 + 1);
      LOBYTE(v31) = 1;
      if ( (int)RtlAnsiStringToUnicodeString(v35, v37, v31) < 0 )
        goto LABEL_76;
      sub_140349713(*((_QWORD *)v2 + 161), *((unsigned int *)v2 + 324), (__int64)v35, (unsigned __int64)v2 + *v2 + 2);
      RtlFreeUnicodeString(v35);
      v32 = *((_QWORD *)v2 + 161);
      if ( v32 )
        goto LABEL_71;
LABEL_74:
      if ( !v27 )
        goto LABEL_73;
LABEL_72:
      KeUnstackDetachProcess(v38);
      PsReleaseProcessExitSynchronization(v29);
      ObfDereferenceObject(v29);
      v2 = (unsigned __int16 *)*((_QWORD *)v2 + 165);
    }
  }
  v3 = sub_140349115();
  dword_140016920[0] = 9;
  v4 = v3;
  dword_140016D80 = 1;
  dword_140016900[0] = -2134605496;
  dword_140016904 = 1593835521;
  byte_140016908 = -61;
  sub_14034F069();
  v36 = -1000000i64;
  do
  {
    be::check_img_notify_still_loaded();
    be::check_bedaisy_dispatch();
    if ( !byte_140016176 )
      goto LABEL_35;
    if ( byte_140016004 )
    {
      if ( !qword_140016788 )
        LODWORD(dword_140016714) = 0;
      v5 = 0x140016714i64;
      if ( qword_140016788 )
        v5 = qword_140016788;
      v6 = ZwQuerySystemInformation(5i64, v5, (unsigned int)dword_140016714, v33);
      if ( v6 == -1073741820 )
      {
        if ( qword_140016788 )
          ExFreePoolWithTag(qword_140016788, 0i64);
        LODWORD(dword_140016714) = v33[0] + 1024;
        v7 = ExAllocatePoolWithTag(1i64, (unsigned int)(v33[0] + 1024), 17730i64);
        qword_140016788 = v7;
        if ( !v7 )
          goto LABEL_35;
        do
        {
          v6 = ZwQuerySystemInformation(5i64, v7, (unsigned int)dword_140016714, v33);
          if ( v6 != -1073741820 )
            break;
          ExFreePoolWithTag(qword_140016788, 0i64);
          LODWORD(dword_140016714) = v33[0] + 1024;
          v7 = ExAllocatePoolWithTag(1i64, (unsigned int)(v33[0] + 1024), 17730i64);
          qword_140016788 = v7;
        }
        while ( v7 );
      }
      if ( v6 < 0 )
        goto LABEL_35;
      byte_140016004 = 0;
      qword_140016790 = qword_140016788;
    }
    v8 = PsGetProcessId(*(_QWORD *)PsInitialSystemProcess);
    for ( j = 0; j < 10; ++j )
    {
      if ( !qword_140016210
        || (v10 = *(_QWORD *)(qword_140016790 + 80), v10 == qword_140016138)
        || v10 == (_QWORD)xmmword_140016150
        || v10 == v8
        || v10 == qword_140016160
        || v10 == qword_140016168
        || byte_140016170 && v10 == qword_140016178
        || *(_QWORD *)(qword_140016790 + 88) == (_QWORD)xmmword_140016150
        || (int)PsLookupProcessByProcessId(v10, v35) < 0 )
      {
        v11 = qword_140016790;
        v12 = *(unsigned int *)qword_140016790;
        if ( !(_DWORD)v12 )
        {
LABEL_34:
          byte_140016004 = 1;
          break;
        }
      }
      else
      {
        sub_14033B383(v35[0], 0i64);
        ObfDereferenceObject(v35[0]);
        v11 = qword_140016790;
        v12 = *(unsigned int *)qword_140016790;
        if ( !(_DWORD)v12 )
          goto LABEL_34;
      }
      qword_140016790 = v11 + v12;
    }
LABEL_35:
    if ( !byte_1400168C8 )
    {
      v13 = be::validate_function_integrity(7, 0i64, (__int128 *)KeInitializeEvent);
      v14 = byte_1400168C8;
      if ( v13 )
        v14 = 1;
      byte_1400168C8 = v14;
      v15 = be::validate_function_integrity(8, 0i64, (__int128 *)KeInitializeApc);
      v16 = byte_1400168C8;
      if ( v15 )
        v16 = 1;
      byte_1400168C8 = v16;
      v17 = be::validate_function_integrity(9, 0i64, (__int128 *)KeInsertQueueApc);
      v18 = byte_1400168C8;
      if ( v17 )
        v18 = 1;
      byte_1400168C8 = v18;
      v19 = be::validate_function_integrity(10, 0i64, (__int128 *)RtlWalkFrameChain);
      v20 = byte_1400168C8;
      if ( v19 )
        v20 = 1;
      byte_1400168C8 = v20;
      v21 = be::validate_function_integrity(11, 0i64, (__int128 *)KeSetEvent);
      v22 = byte_1400168C8;
      if ( v21 )
        v22 = 1;
      byte_1400168C8 = v22;
      v23 = be::validate_function_integrity(12, 0i64, (__int128 *)KeWaitForSingleObject);
      v24 = byte_1400168C8;
      if ( v23 )
        v24 = 1;
      byte_1400168C8 = v24;
    }
    sub_1403471F1(v4);
  }
  while ( (unsigned int)KeWaitForSingleObject(0x1400167B8i64, 0i64, 0i64, 0i64, &v36) );
  if ( qword_140016788 )
    ExFreePoolWithTag(qword_140016788, 0i64);
  return PsTerminateSystemThread(0i64);
}