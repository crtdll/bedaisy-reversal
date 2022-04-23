size_t __fastcall be::handle_request(IRP *a1, unsigned int a2)
{
  __int64 v2; // rbx
  __int64 v4; // r14
  int index; // edi
  int v6; // ecx
  _BYTE *v7; // rax
  unsigned __int64 size; // rsi
  size_t result; // rax
  unsigned int key; // ebx
  _BYTE *buffer; // r14
  int v12; // ecx
  _BYTE *v13; // rsi
  _WORD *v14; // rdx
  __int64 v15; // rsi
  size_t v16; // rsi
  int v17; // eax
  _WORD *v18; // rdx
  __int64 v19; // rsi
  const void **v20; // rbx
  int v21; // eax
  _WORD *v22; // rdx
  __int64 v23; // rsi
  size_t v24; // rsi
  __int64 v25; // rax
  __int64 v26; // rax
  int v27; // ecx
  int v28; // eax
  __int64 _RAX; // rax
  __int64 _RAX; // rax
  __int64 _RDX; // rdx
  __int64 _RCX; // rcx
  __int64 _RBX; // rbx
  int v34; // esi
  unsigned __int64 v35; // rax
  int v36; // ebx
  char v37; // r14
  unsigned __int64 v38; // rdx
  __int64 v39; // rcx
  __int64 v40; // rax
  unsigned __int64 v41; // rdx
  __int64 v42; // rcx
  __int64 v43; // rax
  unsigned __int64 v44; // rdx
  __int64 v45; // rcx
  __int64 v46; // rax
  __int64 v47; // rax
  __int64 v48; // rax
  __int64 v49; // rax
  __int64 _RAX; // rax
  __int64 _RAX; // rax
  __int64 _RDX; // rdx
  __int64 _RCX; // rcx
  __int64 _RBX; // rbx
  __int64 _RAX; // rax
  __int64 _RAX; // rax
  __int64 _RDX; // rdx
  __int64 _RCX; // rcx
  __int64 _RBX; // rbx
  __int64 _RAX; // rax
  __int64 _RAX; // rax
  __int64 _RDX; // rdx
  __int64 _RCX; // rcx
  __int64 _RBX; // rbx
  __int64 _RAX; // rax
  __int64 _RAX; // rax
  __int64 _RDX; // rdx
  __int64 _RCX; // rcx
  __int64 _RBX; // rbx
  _STORAGE_DEVICE_DESCRIPTOR *v70; // rax
  _STORAGE_DEVICE_DESCRIPTOR *v71; // rbx
  __int64 v72; // rsi
  unsigned __int8 v73; // al
  __int64 v74; // rbx
  ST_IDSECTOR *v75; // rax
  ST_IDSECTOR *v76; // rsi
  int v77; // er8
  __int64 v78; // rdx
  unsigned __int64 v79; // rbx
  int i; // ecx
  unsigned __int64 v81; // rbx
  char v82; // dl
  int v83; // ebx
  int j; // er8
  char v85; // dl
  _BYTE *v86; // rsi
  _QWORD *k; // r14
  __int64 v88; // [rsp+20h] [rbp-EE8h]
  __int64 v89; // [rsp+28h] [rbp-EE0h]
  char enc_keys[32]; // [rsp+50h] [rbp-EB8h] BYREF
  __int64 v91; // [rsp+70h] [rbp-E98h] BYREF
  __int64 v92; // [rsp+78h] [rbp-E90h] BYREF
  int v93; // [rsp+80h] [rbp-E88h]
  int v94; // [rsp+84h] [rbp-E84h]
  int v95; // [rsp+88h] [rbp-E80h]
  int v96; // [rsp+8Ch] [rbp-E7Ch]
  _QWORD v97[2]; // [rsp+90h] [rbp-E78h] BYREF
  size_t MaxCount[2]; // [rsp+A0h] [rbp-E68h] BYREF
  int v99; // [rsp+B0h] [rbp-E58h]
  unsigned __int64 v100; // [rsp+B4h] [rbp-E54h]
  int v101; // [rsp+BCh] [rbp-E4Ch]
  __int64 v102; // [rsp+C0h] [rbp-E48h] BYREF
  __int64 v103; // [rsp+C8h] [rbp-E40h]
  const void **v104; // [rsp+D0h] [rbp-E38h] BYREF
  __int64 v105; // [rsp+D8h] [rbp-E30h] BYREF
  __int64 v106; // [rsp+E0h] [rbp-E28h] BYREF
  char v107[4]; // [rsp+E8h] [rbp-E20h] BYREF
  _DWORD v108[3]; // [rsp+ECh] [rbp-E1Ch] BYREF
  _BYTE *v109; // [rsp+F8h] [rbp-E10h]
  struct _UNICODE_STRING v110; // [rsp+100h] [rbp-E08h] BYREF
  __int64 v111; // [rsp+110h] [rbp-DF8h] BYREF
  size_t v112; // [rsp+118h] [rbp-DF0h]
  char v113[8]; // [rsp+120h] [rbp-DE8h] BYREF
  int v114; // [rsp+128h] [rbp-DE0h] BYREF
  int *v115; // [rsp+130h] [rbp-DD8h]
  _QWORD v116[2]; // [rsp+138h] [rbp-DD0h] BYREF
  _QWORD v117[3]; // [rsp+148h] [rbp-DC0h] BYREF
  int v118; // [rsp+160h] [rbp-DA8h]
  __int128 v119; // [rsp+168h] [rbp-DA0h]
  _QWORD v120[3]; // [rsp+178h] [rbp-D90h] BYREF
  int v121; // [rsp+190h] [rbp-D78h]
  __int128 v122; // [rsp+198h] [rbp-D70h]
  _QWORD v123[3]; // [rsp+1A8h] [rbp-D60h] BYREF
  int v124; // [rsp+1C0h] [rbp-D48h]
  __int128 v125; // [rsp+1C8h] [rbp-D40h]
  _QWORD v126[2]; // [rsp+1D8h] [rbp-D30h] BYREF
  char v127[8]; // [rsp+1E8h] [rbp-D20h] BYREF
  int v128; // [rsp+1F0h] [rbp-D18h]
  char v129[8]; // [rsp+200h] [rbp-D08h] BYREF
  int v130; // [rsp+208h] [rbp-D00h]
  __int64 v131; // [rsp+218h] [rbp-CF0h] BYREF
  char v132; // [rsp+222h] [rbp-CE6h]
  int v133[12]; // [rsp+240h] [rbp-CC8h] BYREF
  int v134[12]; // [rsp+270h] [rbp-C98h] BYREF
  int v135[12]; // [rsp+2A0h] [rbp-C68h] BYREF
  _BYTE Dst[2048]; // [rsp+2D0h] [rbp-C38h] BYREF
  _QWORD v137[128]; // [rsp+AD0h] [rbp-438h] BYREF

  v2 = a2;
  ProbeForWrite(a1->UserBuffer, a2, 1i64);
  be::check_img_notify_still_loaded();
  be::check_bedaisy_dispatch();
  v4 = qword_1400161A8;
  index = 0;
  while ( 1 )
  {
    if ( !v4 )
      goto LABEL_32;
    v6 = *(_DWORD *)(v4 + 1048);
    if ( !v6 && !dword_1400168DC )
      break;
    if ( v6 == 1 )
      break;
    v4 = *(_QWORD *)(v4 + 1064);
  }
  if ( *(_DWORD *)(v4 + 0x418) == 1 )
  {
    v111 = 0i64;
    LODWORD(v92) = 0;
    if ( (unsigned int)v2 <= dword_1400168DC )
    {
      _mm_lfence();
      v7 = (unsigned int)v2 <= 0x400 ? Dst : a1->UserBuffer;
      if ( (int)FltReadFile(
                  *(_QWORD *)(v4 + 1032),
                  *(_QWORD *)(v4 + 1040),
                  &v111,
                  (unsigned int)v2,
                  v7,
                  4,
                  &v92,
                  0i64,
                  0i64) >= 0 )
        a1->IoStatus.Information = v2;
    }
LABEL_13:
    dword_1400168DC = 0;
    goto LABEL_14;
  }
LABEL_32:
  if ( qword_1400161B0 && *(_DWORD *)(qword_1400161B0 + 0x218i64) == 2 )
  {
    if ( (unsigned int)v2 <= dword_1400168DC
      && !IoGetTopLevelIrp()
      && (int)ObQueryNameString(*(_QWORD *)(qword_1400161B0 + 0x210i64), &Dst[1024], 1024i64, &enc_keys[16]) >= 0 )
    {
      LODWORD(v117[0]) = 48;
      v117[1] = 0i64;
      v118 = 576;
      v117[2] = &Dst[1024];
      v119 = 0i64;
      LODWORD(v89) = 32;
      LODWORD(v88) = 7;
      if ( (int)ZwOpenFile(&v105, 0x80000000i64, v117, MaxCount, v88, v89) >= 0 )
      {
        if ( (unsigned int)v2 <= 0x400 )
        {
          v13 = Dst;
        }
        else
        {
          _mm_lfence();
          v13 = (_BYTE *)ExAllocatePoolWithTag(1i64, v2, 17730i64);
        }
        if ( !v13 )
          goto LABEL_48;
        _mm_lfence();
        if ( (int)ZwReadFile(v105, 0i64, 0i64, 0i64, MaxCount, v13, v2, 0i64, 0i64) >= 0 )
        {
          if ( v13 != Dst )
          {
            _mm_lfence();
            memcpy(a1->UserBuffer, v13, MaxCount[1]);
          }
          a1->IoStatus.Information = MaxCount[1];
        }
        if ( v13 == Dst )
        {
LABEL_48:
          ZwClose(v105);
        }
        else
        {
          _mm_lfence();
          ExFreePoolWithTag(v13, 0i64);
          ZwClose(v105);
        }
      }
    }
    ObfDereferenceObject(*(_QWORD *)(qword_1400161B0 + 528i64));
    *(_DWORD *)(qword_1400161B0 + 536i64) = 0;
    goto LABEL_13;
  }
  switch ( (_DWORD)v2 )
  {
    case 4:
      *(_DWORD *)Dst = qword_140016138;
      a1->IoStatus.Information = 4i64;
      break;
    case 0x212:
      if ( v4 )
      {
        v14 = (_WORD *)(v4 + 514);
        Dst[0] = 1;
        v15 = -1i64;
        do
          ++v15;
        while ( v14[v15] );
        v16 = 2 * v15;
        memcpy(&Dst[1], v14, v16);
        if ( IoGetTopLevelIrp()
          || (int)qword_1400167A0(*(_QWORD *)(v4 + 1032), *(_QWORD *)(v4 + 1040), v127, 24i64, 5, 0i64) < 0 )
        {
          v17 = 0;
        }
        else
        {
          v17 = v128;
          dword_1400168DC = v128;
        }
        *(_DWORD *)&Dst[v16 + 1] = v17;
        *(_DWORD *)(v4 + 1048) = 1;
        goto LABEL_62;
      }
      if ( qword_1400161B0 && *(_DWORD *)(qword_1400161B0 + 536i64) == 1 )
      {
        Dst[0] = 0;
        v18 = (_WORD *)(qword_1400161B0 + 12i64);
        v19 = -1i64;
        do
          ++v19;
        while ( v18[v19] );
        v16 = 2 * v19;
        v112 = v16;
        memcpy(&Dst[1], v18, v16);
        *(_DWORD *)&Dst[v16 + 1] = 0;
        if ( IoGetTopLevelIrp()
          || (int)ObQueryNameString(*(_QWORD *)(qword_1400161B0 + 528i64), v137, 1024i64, v113) < 0
          || (LODWORD(v120[0]) = 48,
              v120[1] = 0i64,
              v121 = 576,
              v120[2] = v137,
              v122 = 0i64,
              LODWORD(v89) = 32,
              LODWORD(v88) = 7,
              (int)ZwOpenFile(v97, 0x80000000i64, v120, v116, v88, v89) < 0) )
        {
          if ( dword_1400168DC )
            goto LABEL_62;
        }
        else
        {
          if ( (int)ObReferenceObjectByHandle(v97[0], 1179785i64, *IoFileObjectType, 0i64, &v106, 0i64) < 0 )
          {
            v21 = ZwQueryInformationFile(v97[0], v116, v129, 24i64, 5);
          }
          else
          {
            KeGetCurrentIrql();
            if ( (int)IoQueryFileDosDeviceName(v106, &v104) >= 0 )
            {
              v20 = v104;
              v16 = *(unsigned __int16 *)v104;
              v112 = v16;
              memcpy(&Dst[1], v104[1], (unsigned int)v16);
              *(_DWORD *)&Dst[v16 + 1] = 0;
              ExFreePoolWithTag(v20, 0i64);
            }
            ObfDereferenceObject(v106);
            v21 = ZwQueryInformationFile(v97[0], v116, v129, 24i64, 5);
          }
          if ( v21 >= 0 )
          {
            dword_1400168DC = v130;
            *(_DWORD *)&Dst[v16 + 1] = v130;
            *(_DWORD *)(qword_1400161B0 + 536i64) = 2;
          }
          ZwClose(v97[0]);
          if ( dword_1400168DC )
            goto LABEL_62;
        }
        ObfDereferenceObject(*(_QWORD *)(qword_1400161B0 + 528i64));
        *(_DWORD *)(qword_1400161B0 + 536i64) = 0;
LABEL_62:
        a1->IoStatus.Information = v16 + 5;
        break;
      }
      if ( qword_140016820 )
      {
        Dst[0] = 2;
        v22 = (_WORD *)(qword_140016820 + 258);
        v23 = -1i64;
        do
          ++v23;
        while ( v22[v23] );
        v24 = 2 * v23;
        memcpy(&Dst[1], v22, v24);
        v25 = qword_140016820;
        *(_DWORD *)&Dst[v24 + 1] = *(_DWORD *)(qword_140016820 + 1296);
        *(_DWORD *)&Dst[v24 + 5] = *(_DWORD *)(v25 + 1300);
        *(_DWORD *)&Dst[v24 + 9] = *(_DWORD *)(v25 + 1304);
        *(_DWORD *)&Dst[v24 + 13] = *(_DWORD *)(v25 + 1308);
        Dst[v24 + 17] = *(_BYTE *)(v25 + 1312);
        v26 = qword_140016820;
        a1->IoStatus.Information = v24 + 18;
        qword_140016820 = *(_QWORD *)(v26 + 1320);
      }
      break;
    case 0x45:
      Dst[0] = byte_140016172;
      v27 = qword_140016218;
      if ( !qword_140016218 || byte_140016174 )
        v27 = 0;
      *(_DWORD *)&Dst[1] = v27;
      *(_OWORD *)&Dst[5] = xmmword_140016220;
      *(_OWORD *)&Dst[21] = xmmword_140016230;
      *(_OWORD *)&Dst[37] = xmmword_140016240;
      *(_OWORD *)&Dst[53] = xmmword_140016250;
      a1->IoStatus.Information = 0x45i64;
      break;
    case 0x3FC:
      *(_DWORD *)&Dst[1] = 1;
      *(_DWORD *)&Dst[5] = qword_140016138;
      dword_140016480 = 284;
      if ( (int)RtlGetVersion(0x140016480i64) < 0 )
      {
        v28 = 0;
        *(_QWORD *)&Dst[9] = 0i64;
      }
      else
      {
        *(_QWORD *)&Dst[9] = qword_140016484;
        v28 = dword_14001648C;
      }
      *(_DWORD *)&Dst[17] = v28;
      _RAX = 1i64;
      __asm { cpuid }
      v34 = _RCX;
      v99 = _RAX;
      LODWORD(v100) = _RBX;
      v101 = _RDX;
      v35 = __readcr4();
      *(_QWORD *)&Dst[237] = v35;
      v36 = _RCX & 0x4000000;
      if ( (_RCX & 0x4000000) == 0 || (v35 & 0x40000) != 0 )
      {
        v37 = 0;
      }
      else
      {
        v37 = 1;
        __writecr4(v35 | 0x40000);
      }
      *(_QWORD *)&enc_keys[24] = 0xFFFFFFFFFFFE7960ui64;
      *(_QWORD *)&Dst[21] = sub_140005CC0();
      if ( v36 )
        v40 = sub_140005E3C(v39, v38);
      else
        v40 = 0i64;
      *(_QWORD *)&Dst[29] = v40;
      *(_QWORD *)&Dst[37] = sub_140005D84();
      KeDelayExecutionThread(0i64, 0i64, &enc_keys[24]);
      *(_QWORD *)&Dst[45] = sub_140005CC0();
      if ( v36 )
        v43 = sub_140005E3C(v42, v41);
      else
        v43 = 0i64;
      *(_QWORD *)&Dst[53] = v43;
      *(_QWORD *)&Dst[61] = sub_140005D84();
      KeDelayExecutionThread(0i64, 0i64, &enc_keys[24]);
      *(_QWORD *)&Dst[69] = sub_140005CC0();
      if ( v36 )
        v46 = sub_140005E3C(v45, v44);
      else
        v46 = 0i64;
      *(_QWORD *)&Dst[0x4D] = v46;
      *(_QWORD *)&Dst[0x55] = sub_140005D84();
      *(_QWORD *)&Dst[0x5D] = sub_14034DE51(&Dst[165], &Dst[173]);
      if ( v36 )
        v47 = sub_14034DF51(&Dst[181], &Dst[189]);
      else
        v47 = 0i64;
      *(_QWORD *)&Dst[0x65] = v47;
      *(_QWORD *)&Dst[0x6D] = sub_14034DED6((unsigned __int64 *)&Dst[197], &Dst[205]);
      KeDelayExecutionThread(0i64, 0i64, &enc_keys[24]);
      *(_QWORD *)&Dst[0x75] = sub_14034DE51(&Dst[165], &Dst[173]);
      if ( v36 )
        v48 = sub_14034DF51(&Dst[181], &Dst[189]);
      else
        v48 = 0i64;
      *(_QWORD *)&Dst[0x7D] = v48;
      *(_QWORD *)&Dst[0x85] = sub_14034DED6((unsigned __int64 *)&Dst[197], &Dst[205]);
      KeDelayExecutionThread(0i64, 0i64, &enc_keys[24]);
      *(_QWORD *)&Dst[0x8D] = sub_14034DE51(&Dst[165], &Dst[173]);
      if ( v36 )
        v49 = sub_14034DF51(&Dst[181], &Dst[189]);
      else
        v49 = 0i64;
      *(_QWORD *)&Dst[0x95] = v49;
      *(_QWORD *)&Dst[0x9D] = sub_14034DED6((unsigned __int64 *)&Dst[197], &Dst[205]);
      if ( v37 )
        __writecr4(*(unsigned __int64 *)&Dst[237]);
      *(_DWORD *)&Dst[0xD5] = v34;
      if ( (v34 & 0x20) != 0 )
        *(_QWORD *)&Dst[0xD9] = __readmsr(0x3Au);// IA32_FEATURE_CONTROL
      if ( v34 < 0 )
      {
        _RAX = 0x40000000i64;
        __asm { cpuid }
        v99 = _RAX;
        v100 = __PAIR64__(_RCX, _RBX);
        *(_QWORD *)&Dst[0xE1] = __PAIR64__(_RCX, _RBX);
        *(_DWORD *)&Dst[0xE9] = _RDX;
      }
      _RAX = 2147483650i64;
      __asm { cpuid }
      *(_DWORD *)&Dst[0xF5] = _RAX;             // cpu name
      *(_DWORD *)&Dst[0xF9] = _RBX;             // cpu name
      *(_DWORD *)&Dst[0xFD] = _RCX;             // cpu name
      *(_DWORD *)&Dst[0x101] = _RDX;            // cpu name
      _RAX = 2147483651i64;
      __asm { cpuid }
      *(_DWORD *)&Dst[0x105] = _RAX;            // cpu name
      *(_DWORD *)&Dst[0x109] = _RBX;            // cpu name
      *(_DWORD *)&Dst[0x10D] = _RCX;            // cpu name
      _RAX = 2147483652i64;
      *(_DWORD *)&Dst[0x111] = _RDX;            // cpu name
      __asm { cpuid }
      *(_DWORD *)&Dst[0x115] = _RAX;            // cpu name
      *(_DWORD *)&Dst[0x119] = _RBX;            // cpu name
      *(_DWORD *)&Dst[0x11D] = _RCX;            // cpu name
      *(_DWORD *)&Dst[0x121] = _RDX;            // cpu name
      *(_QWORD *)&enc_keys[0x10] = 0x125i64;
      Dst[293] = 0;
      v133[0] = 0x44005C;
      v133[1] = 0x760065;
      v133[2] = 0x630069;
      v133[3] = 0x5C0065;
      v133[4] = 0x610048;
      v133[5] = 0x640072;
      v133[6] = 0x690064;
      v133[7] = 0x6B0073;
      v133[8] = 0x5C0030;
      v133[9] = 0x520044;
      v133[10] = 0x30;
      v114 = 0x2C002A;
      v115 = v133;
      LODWORD(v123[0]) = 0x30;
      v123[1] = 0i64;
      v124 = 576;
      v123[2] = &v114;
      v125 = 0i64;
      LODWORD(v89) = 32;
      LODWORD(v88) = 7;
      if ( (int)ZwOpenFile(&v91, 0xC0000000i64, v123, &v102, v88, v89) < 0 )// \Device\Harddisk0\DR0
      {
        v74 = 294i64;
        *(_QWORD *)&enc_keys[16] = 294i64;
        Dst[294] = 0;
      }
      else
      {
        if ( !byte_1400168E0 )
        {
          v134[0] = 0x77005A;
          v134[1] = 0x650044;
          v134[2] = 0x690076;
          v134[3] = 0x650063;
          v134[4] = 0x6F0049;
          v134[5] = 0x6F0043;
          v134[6] = 0x74006E;
          v134[7] = 0x6F0072;
          v134[8] = 0x46006C;
          v134[9] = 0x6C0069;
          v134[10] = 0x65;
          *(_DWORD *)&v110.Length = 2883626;
          v110.Buffer = (PWSTR)v134;
          if ( be::validate_function_integrity(5, &v110, (__int128 *)ZwDeviceIoControlFile) )
            byte_1400168E0 = 1;
          v135[0] = 0x74004E;
          v135[1] = 0x650044;
          v135[2] = 0x690076;
          v135[3] = 0x650063;
          v135[4] = 0x6F0049;
          v135[5] = 0x6F0043;
          v135[6] = 0x74006E;
          v135[7] = 0x6F0072;
          v135[8] = 0x46006C;
          v135[9] = 0x6C0069;
          v135[10] = 0x65;
          LODWORD(MaxCount[0]) = 0x2C002A;
          MaxCount[1] = (size_t)v135;
          v110 = *(struct _UNICODE_STRING *)MaxCount;
          if ( be::validate_function_integrity(6, &v110, 0i64) )
            byte_1400168E0 = 1;
        }
        v126[0] = 0i64;
        if ( (int)ZwDeviceIoControlFile(v91, 0i64, 0i64, 0i64, &v102, IOCTL_STORAGE_QUERY_PROPERTY, v126, 12, v107, 8) >= 0 )
        {
          if ( v103 )
          {
            v70 = (_STORAGE_DEVICE_DESCRIPTOR *)ExAllocatePoolWithTag(1i64, v108[0], 'EB');
            v71 = v70;
            if ( v70 )
            {
              if ( (int)ZwDeviceIoControlFile(
                          v91,
                          0i64,
                          0i64,
                          0i64,
                          &v102,
                          IOCTL_STORAGE_QUERY_PROPERTY,
                          v126,
                          12,
                          v70,
                          v108[0]) >= 0
                && v103
                && v71->SerialNumberOffset
                && (_mm_lfence(), (unsigned __int8)MmIsAddressValid((char *)v71 + v71->SerialNumberOffset)) )
              {
                _mm_lfence();
                v72 = -1i64;
                do
                  ++v72;
                while ( *((_BYTE *)&v71->Version + v71->SerialNumberOffset + v72) );
                v73 = v72;
                Dst[0x125] = v72;
                if ( (unsigned __int8)v72 > 0x28u )
                  v73 = 0x28;
                Dst[0x125] = v73;
                memcpy(&Dst[0x126], (char *)v71 + v71->SerialNumberOffset, v73);
                ExFreePoolWithTag(v71, 0i64);
              }
              else
              {
                ExFreePoolWithTag(v71, 0i64);
              }
            }
          }
        }
        v74 = Dst[0x125] + 0x126i64;
        *(_QWORD *)&enc_keys[16] = v74;
        Dst[v74] = 0;
        v132 = 0xEC;
        v75 = (ST_IDSECTOR *)ExAllocatePoolWithTag(1i64, 529i64, 17730i64);
        v76 = v75;
        if ( v75 )
        {
          if ( (int)ZwDeviceIoControlFile(v91, 0i64, 0i64, 0i64, &v102, SMART_RCV_DRIVE_DATA, &v131, 33, v75, 529) >= 0
            && v103 )
          {
            Dst[v74] = 0x14;
            v77 = 0;
            HIDWORD(v92) = 0;
            while ( v77 < 19 )
            {
              v78 = v77 + v74;
              Dst[v78 + 1] = v76->sSerialNumber[v77 + 0x11];
              Dst[v78 + 2] = v76->sSerialNumber[v77 + 16];
              v77 += 2;
              HIDWORD(v92) = v77;
            }
          }
          ExFreePoolWithTag(v76, 0i64);
          ZwClose(v91);
        }
        else
        {
          ZwClose(v91);
        }
      }
      v79 = (unsigned __int8)Dst[v74] + 1i64 + v74;
      *(_QWORD *)&enc_keys[16] = v79;
      *(_QWORD *)&v108[1] = MEMORY[0xFFFFF78000000320];
      Dst[0] = RtlRandomEx(&v108[1]);
      if ( v79 >= 0x400 )
        sub_1400138C4();
      Dst[v79] = 0;
      for ( i = 0; ; ++i )
      {
        v93 = i;
        if ( i >= v79 )
          break;
        Dst[v79] += Dst[i];
      }
      v81 = v79 + 1;
      *(_QWORD *)&enc_keys[16] = v81;
      while ( 1 )
      {
        v94 = v81;
        if ( (int)v81 >= 0x16C )
          break;
        *(_DWORD *)&Dst[(int)v81] = RtlRandomEx(&v108[1]);
        LODWORD(v81) = v81 + 4;
      }
      v82 = Dst[0];
      v83 = 0;
      for ( j = 0; ; ++j )
      {
        v95 = v83;
        if ( j >= 0x16B )
          break;
        v85 = v83 ^ Dst[j + 1] ^ v82 ^ 0xA5;
        Dst[j + 1] = v85;
        v82 = ~v85;
        v83 = j + 1;
      }
      a1->IoStatus.Information = 0x16Ci64;
      break;
    case 0x208:
      v86 = Dst;
      v109 = Dst;
      for ( k = (_QWORD *)g_report_head;
            k && (__int64)&v86[*((unsigned int *)k + 2) - (_QWORD)Dst + 2] <= v2;
            g_report_head = k )
      {
        *(_WORD *)v86 = *((_WORD *)k + 4);      // k + 8 = size
        v109 = v86 + 2;
        memcpy(v86 + 2, (const void *)*k, *((unsigned int *)k + 2));
        v86 += *((unsigned int *)k + 2) + 2;
        v109 = v86;
        ExFreePoolWithTag(*k, 0i64);
        k = *(_QWORD **)(g_report_head + 16i64);
        ExFreePoolWithTag(g_report_head, 0i64);
      }
      memset(v86, 0, (size_t)&Dst[v2 - (_QWORD)v86]);
      a1->IoStatus.Information = v2;
      break;
  }
LABEL_14:
  size = a1->IoStatus.Information;
  result = size - 1;
  if ( size - 1 <= 1023 )
  {
    result = (size_t)a1->UserBuffer;
    v104 = (const void **)a1->IoStatus.Information;
    key = *(_DWORD *)result;
    *(_DWORD *)enc_keys = *(_DWORD *)result;
    buffer = Dst;
    if ( result )
      buffer = (_BYTE *)result;
    if ( size <= 4 )
    {
      while ( 1 )
      {
        v96 = index;
        if ( index >= (int)size )
          break;
        buffer[index] = ~(_BYTE)index ^ Dst[index] ^ enc_keys[index];
        result = key >> (index % 32);
        if ( (result & 1) != 0 )
        {
          key = ~(key + 1);
          *(_DWORD *)enc_keys = key;
        }
        ++index;
      }
    }
    else
    {
      if ( buffer == Dst )
        goto LABEL_25;
      memcpy(buffer, Dst, size);
      *(_DWORD *)&enc_keys[8] = 0;
      result = size - 3;
      if ( (int)size - 3 > 0 )
      {
        do
        {
          *(_DWORD *)&buffer[index] ^= key ^ ~index;
          if ( ((key >> (index % 32)) & 1) != 0 )
          {
            key = ~(key + 1);
            *(_DWORD *)enc_keys = key;
          }
          v12 = enc_keys[index % 32] & 3;
          if ( index < (int)size - v12 - 4 )
          {
            index += v12;
            *(_DWORD *)&enc_keys[8] = index;
          }
          ++index;
LABEL_25:
          *(_DWORD *)&enc_keys[8] = index;
          result = size - 3;
        }
        while ( index < (int)size - 3 );
      }
    }
  }
  return result;
}