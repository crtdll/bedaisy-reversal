__int64 be::check_img_notify_still_loaded()
{
  int v1; // [rsp+28h] [rbp-20h]
  char v2; // [rsp+50h] [rbp+8h] BYREF
  bool v3; // [rsp+51h] [rbp+9h]
  __int64 v4; // [rsp+58h] [rbp+10h] BYREF

  KeWaitForSingleObject(0x1400161D8i64, 0i64, 0i64, 0i64, 0i64);
  if ( qword_140016210 )
  {
    byte_140016171 = 0;
    LOBYTE(v1) = 0;
    if ( (int)ObOpenObjectByPointer(qword_140016210, 512i64, 0i64, 0i64, *PsProcessType, v1, &v4) >= 0 )
    {
      if ( byte_140016171 )
      {
        if ( !byte_140016172 )
          goto LABEL_5;
      }
      else if ( byte_140016172 != byte_140016171 )
      {
LABEL_5:
        ZwClose(v4);
        return KeReleaseMutex(0x1400161D8i64, 0i64);
      }
      v2 = 2;
      byte_140016172 = byte_140016171 == 0;
      v3 = byte_140016171 == 0;
      be::report((__int64)&v2, 2i64);
      ZwClose(v4);
      return KeReleaseMutex(0x1400161D8i64, 0i64);
    }
  }
  return KeReleaseMutex(0x1400161D8i64, 0i64);
}