__int64 __fastcall be::stackwalk(__int64 a1, int a2, __int64 a3, char a4)
{
  char v4; // r13
  __int64 v5; // rdi
  __int64 v6; // r15
  __int64 v7; // r12
  __int64 v8; // rbx
  __int64 result; // rax
  unsigned int v10; // esi
  __int64 v11; // rax
  __int64 v12; // r14
  __int64 v13; // rbx
  int v14; // eax
  unsigned int v15; // er10
  int v16; // er11
  unsigned __int64 v17; // rcx
  __int64 v18; // rbx
  unsigned __int64 v19; // rdx
  __int64 v20; // rcx
  unsigned __int64 v21; // r8
  __int64 *v22; // rax
  __int64 v23; // rdi
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // r13
  unsigned int v27; // ebx
  __int64 v28; // rax
  __int64 v29; // rbx
  unsigned __int64 v30; // r8
  _BYTE *v31; // rcx
  unsigned int v32; // esi
  int v33; // ebx
  int *v34; // rdi
  unsigned int v35; // er8
  __int64 v36; // rdx
  _QWORD *v37; // rcx
  int v38; // er9
  __int128 v39; // xmm0
  __int128 v40; // xmm1
  __int128 v41; // xmm0
  int v42; // eax
  __int64 v43; // rdi
  __int128 v44; // xmm1
  __int64 v45; // rcx
  _WORD *v46; // rdx
  __int64 v47; // r8
  __int64 v48; // rcx
  int v49; // eax
  __int64 v50; // rcx
  unsigned __int64 v51; // r8
  __int64 v52; // rcx
  __int64 v53; // rax
  __int64 v54; // rcx
  __int64 v55; // rbx
  __int64 v56; // rdx
  char v57; // si
  __int64 v58; // rdx
  __int64 v59; // rbx
  unsigned int v60; // er14
  __int64 v61; // rbx
  unsigned int v62; // edx
  __int64 v63; // rax
  bool v64; // zf
  char v66; // [rsp+44h] [rbp-BCh]
  unsigned int v67; // [rsp+48h] [rbp-B8h]
  unsigned int v68; // [rsp+4Ch] [rbp-B4h]
  char v69; // [rsp+50h] [rbp-B0h]
  __int64 v72; // [rsp+60h] [rbp-A0h]
  __int64 v73; // [rsp+68h] [rbp-98h] BYREF
  __int64 v74; // [rsp+70h] [rbp-90h] BYREF
  int v75; // [rsp+78h] [rbp-88h] BYREF
  int *v76; // [rsp+80h] [rbp-80h]
  int v77; // [rsp+88h] [rbp-78h] BYREF
  int *v78; // [rsp+90h] [rbp-70h]
  __int64 v79; // [rsp+98h] [rbp-68h]
  __int64 v80; // [rsp+A0h] [rbp-60h]
  char v81[24]; // [rsp+A8h] [rbp-58h] BYREF
  __int64 v82[10]; // [rsp+C0h] [rbp-40h] BYREF
  char v83[2]; // [rsp+110h] [rbp+10h] BYREF
  __int64 v84; // [rsp+112h] [rbp+12h]
  __int128 v85; // [rsp+11Ah] [rbp+1Ah]
  __int128 v86; // [rsp+12Ah] [rbp+2Ah]
  __int128 v87; // [rsp+13Ah] [rbp+3Ah]
  __int128 v88; // [rsp+14Ah] [rbp+4Ah]
  int v89; // [rsp+15Ah] [rbp+5Ah]
  char v90; // [rsp+15Eh] [rbp+5Eh]
  int v91[48]; // [rsp+15Fh] [rbp+5Fh] BYREF

  v4 = a4;
  v5 = a3;
  v6 = a1;
  v80 = a1;
  v7 = 10i64 * (unsigned int)a2;
  v8 = *(_QWORD *)(a1 + 80i64 * (unsigned int)a2 + 304);
  result = PsGetCurrentThreadId(a1);
  if ( v8 != result )
  {
    result = PsLookupThreadByThreadId(v8, &v74);
    v10 = 0;
    if ( (int)result >= 0 )
    {
      v11 = ExAllocatePool(512i64, 2168i64);
      v79 = v11;
      v12 = v11;
      if ( v11 )
      {
        v13 = v11 + 88;
        KeInitializeEvent(v11 + 88, 0i64, 0i64);
        KeInitializeApc(v12, v74, 0i64, sub_14000BFA8, 0i64, 0i64, 0, 0i64);
        if ( (unsigned __int8)KeInsertQueueApc(v12, v12, 0i64, 2i64) )
        {
          v73 = -1000000i64;
          v14 = KeWaitForSingleObject(v13, 0i64, 0i64, 0i64, &v73);
          if ( v14 )
          {
            if ( v14 != 258
              || !(unsigned __int8)sub_14034D46C(v12)
              && (unsigned int)KeWaitForSingleObject(v13, 0i64, 0i64, 0i64, &v73) )
            {
              return ObfDereferenceObject(v74);
            }
          }
          else
          {
            KeWaitForSingleObject(&qword_1400161D8, 0i64, 0i64, 0i64, 0i64);
            v15 = *(_DWORD *)(v12 + 2160);
            v69 = 1;
            v16 = 1;
            if ( v15 > 1 )
            {
              while ( 1 )
              {
                if ( v5 || *(_QWORD *)(v12 + 8i64 * v16 + 112) >= 0x8000000000000000ui64 )
                {
                  v17 = *(_QWORD *)(g_driver_object + 24);
                  v18 = v16;
                  v72 = v16;
                  v19 = *(_QWORD *)(v12 + 8i64 * v16 + 112);
                  if ( v19 < v17 || v19 >= v17 + *(unsigned int *)(g_driver_object + 32) )
                  {
                    v20 = qword_140016828;
                    if ( !qword_140016828 )
                      break;
                    do
                    {
                      v21 = *(_QWORD *)(v20 + 1288);
                      if ( v19 >= v21 && v19 < v21 + *(unsigned int *)(v20 + 1296) )
                        break;
                      v20 = *(_QWORD *)(v20 + 1320);
                    }
                    while ( v20 );
                    if ( !v20 )
                      break;
                  }
                }
                v69 = ++v16;
                if ( v16 >= v15 )
                  goto LABEL_17;
              }
              v22 = qword_140016DA8;
              v23 = 0i64;
              do
              {
                v24 = *(v22 - 1);
                if ( !v24 || *(_QWORD *)(v6 + 8 * v7 + 304) == v24 && v19 == *v22 )
                  break;
                ++v10;
                v22 += 2;
              }
              while ( v10 < 0xA );
              if ( (v67 = v10, v10 < 0xA) && !qword_140016DA0[2 * (int)v10] || v4 )
              {
                v25 = ExAllocatePool(512i64, 64i64);
                v26 = v25;
                if ( v25 )
                {
                  if ( (int)((__int64 (__fastcall *)(_QWORD, __int64))sub_14034D4AA)(
                              *(_QWORD *)(v12 + 8 * v18 + 112),
                              v25) >= 0 )
                  {
                    _mm_lfence();
                    v66 = 0;
                    v27 = 0;
                    v68 = 0;
                    v28 = 0i64;
                    while ( *(_BYTE *)(v28 + v26) != 0xE9 )
                    {
                      ++v27;
                      if ( ++v28 >= 60 )
                        goto LABEL_34;
                    }
                    v23 = ExAllocatePool(512i64, 64i64);
                    if ( v23 )
                    {
                      v57 = 0;
                      v58 = v27 + (__int64)*(int *)(v27 + v26 + 1);
                      v59 = *(_QWORD *)(v12 + 8 * v72 + 112);
                      v60 = 0;
                      v61 = v58 + v59 + 5;
                      do
                      {
                        if ( !(unsigned __int8)MmIsAddressValid(v61) || (int)sub_14002D722(v61, v23) < 0 )
                          break;
                        if ( v60 < 0xA )
                          v82[v60] = v61;
                        ++v60;
                        v62 = 0;
                        v63 = 0i64;
                        if ( v60 == 5 )
                          v57 = 1;
                        while ( *(_BYTE *)(v63 + v23) != 0xE9 )
                        {
                          ++v62;
                          if ( ++v63 >= 60 )
                            goto LABEL_96;
                        }
                        v61 += v62 + *(int *)(v63 + v23 + 1) + 5i64;
LABEL_96:
                        ;
                      }
                      while ( v62 != 60 && v60 < 0x64 );
                      v68 = v60;
                      v66 = v57;
                      ExFreePoolWithTag(v23, 0i64);
                      v12 = v79;
                      v23 = 0i64;
                      v6 = v80;
                      v64 = v57 == 0;
                      v10 = v67;
                      if ( !v64 )
                        goto LABEL_53;
                    }
LABEL_34:
                    v29 = a3;
                    if ( a3 != qword_140016830
                      || (unsigned __int8)MmIsAddressValid(*(_QWORD *)(v6 + 8 * v7 + 288))
                      && ((v31 = *(_BYTE **)(v6 + 8 * v7 + 288), *v31 == 0xCC)
                       || *v31 == 0x90
                       || ((*(_WORD *)v31 + 7681) & 0xBFFF) == 0) )
                    {
                      v66 = 1;
                      goto LABEL_54;
                    }
                    v32 = dword_140016D80;
                    v33 = v23;
                    if ( dword_140016D80 )
                    {
                      v34 = dword_140016920;
                      while ( (unsigned int)sub_140013A60(
                                              (unsigned __int64 *)v26,
                                              (__int64)&dword_140016900[9 * v33],
                                              v30) )
                      {
                        v34 += 9;
                        if ( ++v33 >= v32 )
                        {
                          v23 = 0i64;
                          goto LABEL_44;
                        }
                      }
                      v10 = v67;
                      v66 = 1;
                      goto LABEL_53;
                    }
LABEL_44:
                    v35 = v23;
                    if ( a2 >= 50 )
                    {
                      v36 = v23;
                      v37 = (_QWORD *)(v6 + 288);
                      v38 = a2;
                      while ( v36 < 20 && v35 < *(_DWORD *)(v6 + 4) )
                      {
                        if ( *(v37 - 2) == *(_QWORD *)(v6 + 8 * v7 + 272) && *v37 == *(_QWORD *)(v6 + 8 * v7 + 288) )
                        {
                          v66 = 1;
                          goto LABEL_52;
                        }
                        ++v35;
                        --v38;
                        ++v36;
                        v37 += 10;
                        if ( v38 < 50 )
                          break;
                      }
                    }
                    if ( a4 != (_BYTE)v23 )
                    {
LABEL_52:
                      v10 = v67;
LABEL_53:
                      v29 = a3;
LABEL_54:
                      v39 = *(_OWORD *)v26;
                      v83[1] = v69;
                      v40 = *(_OWORD *)(v26 + 16);
                      v85 = v39;
                      v83[0] = 0xE;
                      v41 = *(_OWORD *)(v26 + 32);
                      v84 = *(_QWORD *)(v12 + 8 * v72 + 112);
                      v42 = *(_DWORD *)(v6 + 8 * v7 + 304);
                      v86 = v40;
                      v89 = v42;
                      v43 = 0i64;
                      v44 = *(_OWORD *)(v26 + 48);
                      v87 = v41;
                      v88 = v44;
                      if ( v29 )
                      {
                        v45 = -1i64;
                        do
                          ++v45;
                        while ( *(_WORD *)(v29 + 2 * v45 + 258) );
                        if ( (int)v45 >= 0 )
                        {
                          v46 = (_WORD *)(v29 + 2 * ((int)v45 + 129i64));
                          while ( 1 )
                          {
                            v47 = (unsigned int)v45;
                            --v46;
                            LODWORD(v45) = v45 - 1;
                            if ( (_DWORD)v45 == -1 || *v46 == 92 || *v46 == 47 )
                              break;
                            if ( (int)v45 < 0 )
                              goto LABEL_63;
                          }
                          _mm_lfence();
                          RtlInitUnicodeString(v81, v29 + 2 * (v47 + 129));
                          v75 = 0x400000;
                          v76 = v91;
                          if ( (int)RtlUnicodeStringToAnsiString(&v75, v81, 0i64) >= 0 )
                            v43 = (unsigned __int16)v75;
                        }
                      }
                      else
                      {
                        v77 = 0x400000;
                        v78 = v91;
                        if ( (int)RtlUnicodeStringToAnsiString(&v77, v6 + 56, 0i64) >= 0 )
                          v43 = (unsigned __int16)v77;
                      }
LABEL_63:
                      v90 = v43;
                      if ( v29 )
                        v48 = *(_QWORD *)(v29 + 1288);
                      else
                        LODWORD(v48) = 0;
                      v49 = *(_DWORD *)(v6 + 8 * v7 + 288) - v48;
                      v50 = *(_QWORD *)(v6 + 8 * v7 + 288);
                      *(int *)((char *)v91 + v43) = v49;
                      if ( (unsigned __int8)MmIsAddressValid(v50) )
                        *(_OWORD *)((char *)&v91[1] + v43) = *(_OWORD *)*(_QWORD *)(v6 + 8 * v7 + 288);
                      else
                        *(_OWORD *)((char *)&v91[1] + v43) = 0i64;
                      v52 = *(_QWORD *)(v6 + 8 * v7 + 272);
                      v53 = MEMORY[0xFFFFF78000000014] - v52;
                      v54 = v52 - *(_QWORD *)(v6 + 32);
                      *(_QWORD *)((char *)&v91[5] + v43) = v53;
                      LOWORD(v53) = *(_WORD *)(v6 + 4) - a2 - 1;
                      *(_QWORD *)((char *)&v91[7] + v43 + 2) = v54;
                      *(_WORD *)((char *)&v91[7] + v43) = v53;
                      *((_BYTE *)&v91[9] + v43 + 2) = v68;
                      v55 = 8i64 * v68;
                      if ( v68 > 0xA )
                        v55 = 80i64;
                      ((void (__fastcall *)(__m128i *, unsigned __int64, unsigned __int64))memcpy)(
                        (__m128i *)((char *)&v91[9] + v43 + 3),
                        (unsigned __int64)v82,
                        v51);
                      v56 = v43 + v55 + 0x76;
                      if ( !v66 || v10 >= 0xA || qword_140016DA0[2 * (int)v10] )
                      {
                        ((void (__fastcall *)(char *, __int64))j_be::report_custom_list)(v83, v56);
                      }
                      else
                      {
                        j_j_be::report_internal_0((__int64)v83, v56);
                        qword_140016DA0[2 * (int)v10] = *(_QWORD *)(v6 + 8 * v7 + 304);
                        qword_140016DA8[2 * (int)v10] = *(_QWORD *)(v12 + 8 * v72 + 112);
                      }
                      goto LABEL_73;
                    }
                  }
LABEL_73:
                  ExFreePoolWithTag(v26, 0i64);
                }
              }
            }
LABEL_17:
            KeReleaseMutex(&qword_1400161D8, 0i64);
          }
        }
        ExFreePoolWithTag(v12, 0i64);
      }
      return ObfDereferenceObject(v74);
    }
  }
  return result;
}