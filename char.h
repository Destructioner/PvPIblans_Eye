#ifndef CHAR_H
#define CHAR_H
#endif

static unsigned int len(const void *Buff);

#define EQUALLED 0
#define NOT_EQUALLED -1
#define NOT_FOUND -2

#define _start_memory_ do{
#define _end_free_memory_ }while (0);




#define ZeroBuffer(buffer, size_buffer) do {for (unsigned long ZeroSet = 0; ZeroSet < size_buffer; *(buffer + ZeroSet) = 0, ++ZeroSet);} while (0);

#define convert_to_char(buffer, NumConvert) do {int ConvertTemp = NumConvert; char WriteStr = 0; unsigned char WriteOut = 0; char NumStr[20] = {0}; ZeroBuffer(NumStr, 20); while (ConvertTemp > 0) { switch (ConvertTemp % 10) {case 0:NumStr[WriteStr] = '0';++WriteStr;break;case 1:NumStr[WriteStr] = '1';++WriteStr;break;case 2:NumStr[WriteStr] = '2';++WriteStr;break;case 3:NumStr[WriteStr] = '3';++WriteStr;break;case 4:NumStr[WriteStr] = '4';++WriteStr;break;case 5:NumStr[WriteStr] = '5';++WriteStr;break;case 6:NumStr[WriteStr] = '6';++WriteStr;break;case 7:NumStr[WriteStr] = '7';++WriteStr;break;case 8:NumStr[WriteStr] = '8';++WriteStr;break;	case 9:NumStr[WriteStr] = '9';++WriteStr;break;}ConvertTemp /= 10;}--WriteStr;for (; WriteStr >= 0; --WriteStr, ++WriteOut) {buffer[WriteOut] = NumStr[WriteStr];}} while (0);

#define SetZeroMemory(addr, size_memory) do { unsigned char *AddrSet = (unsigned char *) addr; for (unsigned long MemorySet = 0; MemorySet < size_memory; *(AddrSet + MemorySet) = 0, ++MemorySet);} while (0);

#define CopyMemoryZ(addr_in, addr_out, size_addr_out) do {unsigned char *AddrIn = (unsigned char *) addr_in; unsigned char *AddrOut = (unsigned char *) addr_out; for (unsigned long CopyIng = 0; CopyIng < size_addr_out; *(AddrIn + CopyIng) = *(AddrOut + CopyIng), ++CopyIng);} while(0);

#define CopyBuffer(InBuffer, OutBuffer) do {for (unsigned long BufCopy = 0; *(OutBuffer + BufCopy); *(InBuffer + BufCopy) = *(OutBuffer + BufCopy), ++BufCopy);} while (0);

#define ClearBuffer(buffer) do {for (unsigned long Clearning = 0; *(buffer + Clearning); *(buffer + Clearning) = 0, ++Clearning);} while (0);

#define Append(buffer, SymbAppend) do {*(buffer + len(buffer)) = SymbAppend;} while (0);

#define AppendBuffer(buffer, buffer_from) do {for (unsigned int LengthSrc = len(buffer), WriteInto = 0; *(buffer_from + WriteInto); *(buffer + LengthSrc) = *(buffer_from + WriteInto), ++LengthSrc, ++WriteInto);} while (0);

#define ReadUntil(buffer_from, buffer_in, index_start, index_end) do {for (unsigned int WriteIn = 0, CopyInd_start = index_start, CopyEnd = index_end; CopyInd_start <= CopyEnd; *(buffer_in + WriteIn) = *(buffer_from + CopyInd_start), ++WriteIn, ++CopyInd_start);} while (0);

#define ReadUntilwithIndex(buffer, buffer_in, StartIndex, EndSymbol) do { for (unsigned long Write_offset = 0, IndexStart = StartIndex; *(buffer + IndexStart) != EndSymbol; *(buffer_in + Write_offset) = *(buffer + IndexStart), ++Write_offset, ++IndexStart); } while(0);

#define ReadUntilBuffer(buffer, buffer_in, Index_Start, EndBuffer) do {unsigned long Index = Index_Start; ReadUntil(buffer, buffer_in, Index, find_index(buffer, EndBuffer, Index));} while (0);

#define Replace(buffer, src, dst) do {for (unsigned int ReplaceIter = 0; *(buffer + ReplaceIter); ++ReplaceIter) {if (*(buffer + ReplaceIter) == src) {*(buffer + ReplaceIter) = dst;}}} while (0);

#define ReplaceBuffer(buffer, src, buffer_to_replace) do {const unsigned int LengthTemp = len(buffer) + 1; const unsigned int LengthDst = len(buffer_to_replace); unsigned char TempBuffer[LengthTemp];ZeroBuffer(TempBuffer, LengthTemp); CopyBuffer(TempBuffer, buffer); ClearBuffer(buffer);for (unsigned int ToReplace = 0; ToReplace < LengthTemp; ++ToReplace){if (TempBuffer[ToReplace] == src){AppendBuffer(buffer, buffer_to_replace);continue;}Append(buffer, TempBuffer[ToReplace]);}} while (0);

#define ReplaceBuffer_Buffer(buffer, src_replace, dst_replace) do {if (find(buffer, src_replace) == -1) break; unsigned int LenSrc = len(src_replace); unsigned int LenBuffer = len(buffer) + 1; char TempBuffer[LenBuffer]; ZeroBuffer(TempBuffer, LenBuffer); CopyBuffer(TempBuffer, buffer); ClearBuffer(buffer); int OffsetSrc = find(TempBuffer, src_replace); for (unsigned int WriteOut = 0; WriteOut < LenBuffer; ++WriteOut) { if (WriteOut == OffsetSrc) {AppendBuffer(buffer, dst_replace); OffsetSrc = find_index(TempBuffer, src_replace, WriteOut); WriteOut += LenSrc;}Append(buffer, TempBuffer[WriteOut]);}} while (0);

#define ReplaceChar(buffer, buf_into_replace, into_char) do {const unsigned int LenBuffer = len(buffer) + 1; const unsigned int buf_len = len(buf_into_replace); char TempBuffer[LenBuffer]; ZeroBuffer(TempBuffer, LenBuffer); CopyBuffer(TempBuffer, buffer); ClearBuffer(buffer); for (unsigned int IntoBuf = 0; TempBuffer[IntoBuf]; ++IntoBuf) {if (IntoBuf == find_index(TempBuffer, buf_into_replace, IntoBuf)) {Append(buffer, into_char); IntoBuf += buf_len;}Append(buffer, TempBuffer[IntoBuf]);}} while (0);

#define EncodeURL(URL, size_url) do {unsigned char UrlTemp[size_url];ZeroBuffer(UrlTemp, size_url);CopyBuffer(UrlTemp, URL);ClearBuffer(URL);for (unsigned int IterRus = 0; *(UrlTemp + IterRus); ++IterRus) {if (*(UrlTemp + IterRus) == 0xD0 || *(UrlTemp + IterRus) == 0xD1) {Append(URL, '%');AppendBuffer(URL, hex_byte(*(UrlTemp + IterRus)));++IterRus;Append(URL, '%');AppendBuffer(URL, hex_byte(*(UrlTemp + IterRus)));continue;}Append(URL, *(UrlTemp + IterRus));} ReplaceBuffer(URL, '\r', "%0D\0");ReplaceBuffer(URL, '\n', "%0A\0");ReplaceBuffer(URL, '~', "%7E\0");ReplaceBuffer(URL, (const char) 39, "27%\0");ReplaceBuffer(URL, '?', "%3F\0");ReplaceBuffer(URL, '#', "23%\0");ReplaceBuffer_Buffer(URL, "№", "%E2%84%96\0");ReplaceBuffer(URL, '^', "%5E\0");ReplaceBuffer(URL, '+', "%2B\0");ReplaceBuffer(URL, '*', "%2A\0");ReplaceBuffer(URL, ':', "%3A\0");ReplaceBuffer(URL, ',', "%2C\0");ReplaceBuffer(URL, '{', "%7B\0");ReplaceBuffer(URL, '}', "%7D\0");ReplaceBuffer(URL, '[', "%5B\0");ReplaceBuffer(URL, ']', "%5D\0");ReplaceBuffer(URL, '<', "%3C\0");ReplaceBuffer(URL, '>', "%3E\0");ReplaceBuffer(URL, '/', "%2F\0");ReplaceBuffer(URL, '\\', "%5C\0");ReplaceBuffer(URL, ' ', "%20");} while (0);



static const char *hex_byte(unsigned char BYTE);
static unsigned char cmp(const void *dest, const void *src);
static int find(const void *Dest, const void *SearchSrc);
static int find_index(const void *Dest, const void *SearchSrc, unsigned int position);
static void DeleteBuffer(void *buffer, const void *buffer_delete);

#ifdef _WINSOCK2API_
const char *gethost_ip(const char *host);
#endif

#ifdef _INET_H_
const char *gethost_ip(const char *host);
#endif


static unsigned int len(const void *Buff) {
    const unsigned char *buffer = (const unsigned char *) Buff;
    unsigned int Length = 0;

    for (; *(buffer + Length); ++Length);

    return Length;
}

static const char *hex_byte(unsigned char BYTE) {
	const char *hex[] = {"00\0", "01\0", "02\0", "03\0", "04\0", "05\0", "06\0", "07\0", "08\0", "09\0", "0A\0", "0B\0", "0C\0", "0D\0", "0E\0", "0F\0", "10\0", "11\0", "12\0", "13\0", "14\0", "15\0", "16\0", "17\0", "18\0", "19\0", "1A\0", "1B\0", "1C\0", "1D\0", "1E\0", "1F\0", "20\0", "21\0", "22\0", "23\0", "24\0", "25\0", "26\0", "27\0", "28\0", "29\0", "2A\0", "2B\0", "2C\0", "2D\0", "2E\0", "2F\0", "30\0", "31\0", "32\0", "33\0", "34\0", "35\0", "36\0", "37\0", "38\0", "39\0", "3A\0", "3B\0", "3C\0", "3D\0", "3E\0", "3F\0", "40\0", "41\0", "42\0", "43\0", "44\0", "45\0", "46\0", "47\0", "48\0", "49\0", "4A\0", "4B\0", "4C\0", "4D\0", "4E\0", "4F\0", "50\0", "51\0", "52\0", "53\0", "54\0", "55\0", "56\0", "57\0", "58\0", "59\0", "5A\0", "5B\0", "5C\0", "5D\0", "5E\0", "5F\0", "60\0", "61\0", "62\0", "63\0", "64\0", "65\0", "66\0", "67\0", "68\0", "69\0", "6A\0", "6B\0", "6C\0", "6D\0", "6E\0", "6F\0", "70\0", "71\0", "72\0", "73\0", "74\0", "75\0", "76\0", "77\0", "78\0", "79\0", "7A\0", "7B\0", "7C\0", "7D\0", "7E\0", "7F\0", "80\0", "81\0", "82\0", "83\0", "84\0", "85\0", "86\0", "87\0", "88\0", "89\0", "8A\0", "8B\0", "8C\0", "8D\0", "8E\0", "8F\0", "90\0", "91\0", "92\0", "93\0", "94\0", "95\0", "96\0", "97\0", "98\0", "99\0", "9A\0", "9B\0", "9C\0", "9D\0", "9E\0", "9F\0", "A0\0", "A1\0", "A2\0", "A3\0", "A4\0", "A5\0", "A6\0", "A7\0", "A8\0", "A9\0", "AA\0", "AB\0", "AC\0", "AD\0", "AE\0", "AF\0", "B0\0", "B1\0", "B2\0", "B3\0", "B4\0", "B5\0", "B6\0", "B7\0", "B8\0", "B9\0", "BA\0", "BB\0", "BC\0", "BD\0", "BE\0", "BF\0", "C0\0", "C1\0", "C2\0", "C3\0", "C4\0", "C5\0", "C6\0", "C7\0", "C8\0", "C9\0", "CA\0", "CB\0", "CC\0", "CD\0", "CE\0", "CF\0", "D0\0", "D1\0", "D2\0", "D3\0", "D4\0", "D5\0", "D6\0", "D7\0", "D8\0", "D9\0", "DA\0", "DB\0", "DC\0", "DD\0", "DE\0", "DF\0", "E0\0", "E1\0", "E2\0", "E3\0", "E4\0", "E5\0", "E6\0", "E7\0", "E8\0", "E9\0", "EA\0", "EB\0", "EC\0", "ED\0", "EE\0", "EF\0", "F0\0", "F1\0", "F2\0", "F3\0", "F4\0", "F5\0", "F6\0", "F7\0", "F8\0", "F9\0", "FA\0", "FB\0", "FC\0", "FD\0", "FE\0", "FF\0"};
	
	return hex[(unsigned short) BYTE];
}

static unsigned char byte_hex(const char *hex_data) {
	if (cmp(hex_data, "00\0"))   return 0x00;

    if (cmp(hex_data, "01\0"))   return 0x01;

    if (cmp(hex_data, "02\0"))   return 0x02;

    if (cmp(hex_data, "03\0"))   return 0x03;

    if (cmp(hex_data, "04\0"))   return 0x04;

    if (cmp(hex_data, "05\0"))   return 0x05;

    if (cmp(hex_data, "06\0"))   return 0x06;

    if (cmp(hex_data, "07\0"))   return 0x07;

    if (cmp(hex_data, "08\0"))   return 0x08;

    if (cmp(hex_data, "09\0"))   return 0x09;

    if (cmp(hex_data, "0A\0"))   return 0x0A;

    if (cmp(hex_data, "0B\0"))   return 0x0B;

    if (cmp(hex_data, "0C\0"))   return 0x0C;

    if (cmp(hex_data, "0D\0"))   return 0x0D;

    if (cmp(hex_data, "0E\0"))   return 0x0E;

    if (cmp(hex_data, "0F\0"))   return 0x0F;

    if (cmp(hex_data, "10\0"))   return 0x10;

    if (cmp(hex_data, "11\0"))   return 0x11;

    if (cmp(hex_data, "12\0"))   return 0x12;

    if (cmp(hex_data, "13\0"))   return 0x13;

    if (cmp(hex_data, "14\0"))   return 0x14;

    if (cmp(hex_data, "15\0"))   return 0x15;

    if (cmp(hex_data, "16\0"))   return 0x16;

    if (cmp(hex_data, "17\0"))   return 0x17;

    if (cmp(hex_data, "18\0"))   return 0x18;

    if (cmp(hex_data, "19\0"))   return 0x19;

    if (cmp(hex_data, "1A\0"))   return 0x1A;

    if (cmp(hex_data, "1B\0"))   return 0x1B;

    if (cmp(hex_data, "1C\0"))   return 0x1C;

    if (cmp(hex_data, "1D\0"))   return 0x1D;

    if (cmp(hex_data, "1E\0"))   return 0x1E;

    if (cmp(hex_data, "1F\0"))   return 0x1F;

    if (cmp(hex_data, "20\0"))   return 0x20;

    if (cmp(hex_data, "21\0"))   return 0x21;

    if (cmp(hex_data, "22\0"))   return 0x22;

    if (cmp(hex_data, "23\0"))   return 0x23;

    if (cmp(hex_data, "24\0"))   return 0x24;

    if (cmp(hex_data, "25\0"))   return 0x25;

    if (cmp(hex_data, "26\0"))   return 0x26;

    if (cmp(hex_data, "27\0"))   return 0x27;

    if (cmp(hex_data, "28\0"))   return 0x28;

    if (cmp(hex_data, "29\0"))   return 0x29;

    if (cmp(hex_data, "2A\0"))   return 0x2A;

    if (cmp(hex_data, "2B\0"))   return 0x2B;

    if (cmp(hex_data, "2C\0"))   return 0x2C;

    if (cmp(hex_data, "2D\0"))   return 0x2D;

    if (cmp(hex_data, "2E\0"))   return 0x2E;

    if (cmp(hex_data, "2F\0"))   return 0x2F;

    if (cmp(hex_data, "30\0"))   return 0x30;

    if (cmp(hex_data, "31\0"))   return 0x31;

    if (cmp(hex_data, "32\0"))   return 0x32;

    if (cmp(hex_data, "33\0"))   return 0x33;

    if (cmp(hex_data, "34\0"))   return 0x34;

    if (cmp(hex_data, "35\0"))   return 0x35;

    if (cmp(hex_data, "36\0"))   return 0x36;

    if (cmp(hex_data, "37\0"))   return 0x37;

    if (cmp(hex_data, "38\0"))   return 0x38;

    if (cmp(hex_data, "39\0"))   return 0x39;

    if (cmp(hex_data, "3A\0"))   return 0x3A;

    if (cmp(hex_data, "3B\0"))   return 0x3B;

    if (cmp(hex_data, "3C\0"))   return 0x3C;

    if (cmp(hex_data, "3D\0"))   return 0x3D;

    if (cmp(hex_data, "3E\0"))   return 0x3E;

    if (cmp(hex_data, "3F\0"))   return 0x3F;

    if (cmp(hex_data, "40\0"))   return 0x40;

    if (cmp(hex_data, "41\0"))   return 0x41;

    if (cmp(hex_data, "42\0"))   return 0x42;

    if (cmp(hex_data, "43\0"))   return 0x43;

    if (cmp(hex_data, "44\0"))   return 0x44;

    if (cmp(hex_data, "45\0"))   return 0x45;

    if (cmp(hex_data, "46\0"))   return 0x46;

    if (cmp(hex_data, "47\0"))   return 0x47;

    if (cmp(hex_data, "48\0"))   return 0x48;

    if (cmp(hex_data, "49\0"))   return 0x49;

    if (cmp(hex_data, "4A\0"))   return 0x4A;

    if (cmp(hex_data, "4B\0"))   return 0x4B;

    if (cmp(hex_data, "4C\0"))   return 0x4C;

    if (cmp(hex_data, "4D\0"))   return 0x4D;

    if (cmp(hex_data, "4E\0"))   return 0x4E;

    if (cmp(hex_data, "4F\0"))   return 0x4F;

    if (cmp(hex_data, "50\0"))   return 0x50;

    if (cmp(hex_data, "51\0"))   return 0x51;

    if (cmp(hex_data, "52\0"))   return 0x52;

    if (cmp(hex_data, "53\0"))   return 0x53;

    if (cmp(hex_data, "54\0"))   return 0x54;

    if (cmp(hex_data, "55\0"))   return 0x55;

    if (cmp(hex_data, "56\0"))   return 0x56;

    if (cmp(hex_data, "57\0"))   return 0x57;

    if (cmp(hex_data, "58\0"))   return 0x58;

    if (cmp(hex_data, "59\0"))   return 0x59;

    if (cmp(hex_data, "5A\0"))   return 0x5A;

    if (cmp(hex_data, "5B\0"))   return 0x5B;

    if (cmp(hex_data, "5C\0"))   return 0x5C;

    if (cmp(hex_data, "5D\0"))   return 0x5D;

    if (cmp(hex_data, "5E\0"))   return 0x5E;

    if (cmp(hex_data, "5F\0"))   return 0x5F;

    if (cmp(hex_data, "60\0"))   return 0x60;

    if (cmp(hex_data, "61\0"))   return 0x61;

    if (cmp(hex_data, "62\0"))   return 0x62;

    if (cmp(hex_data, "63\0"))   return 0x63;

    if (cmp(hex_data, "64\0"))   return 0x64;

    if (cmp(hex_data, "65\0"))   return 0x65;

    if (cmp(hex_data, "66\0"))   return 0x66;

    if (cmp(hex_data, "67\0"))   return 0x67;

    if (cmp(hex_data, "68\0"))   return 0x68;

    if (cmp(hex_data, "69\0"))   return 0x69;

    if (cmp(hex_data, "6A\0"))   return 0x6A;

    if (cmp(hex_data, "6B\0"))   return 0x6B;

    if (cmp(hex_data, "6C\0"))   return 0x6C;

    if (cmp(hex_data, "6D\0"))   return 0x6D;

    if (cmp(hex_data, "6E\0"))   return 0x6E;

    if (cmp(hex_data, "6F\0"))   return 0x6F;

    if (cmp(hex_data, "70\0"))   return 0x70;

    if (cmp(hex_data, "71\0"))   return 0x71;

    if (cmp(hex_data, "72\0"))   return 0x72;

    if (cmp(hex_data, "73\0"))   return 0x73;

    if (cmp(hex_data, "74\0"))   return 0x74;

    if (cmp(hex_data, "75\0"))   return 0x75;

    if (cmp(hex_data, "76\0"))   return 0x76;

    if (cmp(hex_data, "77\0"))   return 0x77;

    if (cmp(hex_data, "78\0"))   return 0x78;

    if (cmp(hex_data, "79\0"))   return 0x79;

    if (cmp(hex_data, "7A\0"))   return 0x7A;

    if (cmp(hex_data, "7B\0"))   return 0x7B;

    if (cmp(hex_data, "7C\0"))   return 0x7C;

    if (cmp(hex_data, "7D\0"))   return 0x7D;

    if (cmp(hex_data, "7E\0"))   return 0x7E;

    if (cmp(hex_data, "7F\0"))   return 0x7F;

    if (cmp(hex_data, "80\0"))   return 0x80;

    if (cmp(hex_data, "81\0"))   return 0x81;

    if (cmp(hex_data, "82\0"))   return 0x82;

    if (cmp(hex_data, "83\0"))   return 0x83;

    if (cmp(hex_data, "84\0"))   return 0x84;

    if (cmp(hex_data, "85\0"))   return 0x85;

    if (cmp(hex_data, "86\0"))   return 0x86;

    if (cmp(hex_data, "87\0"))   return 0x87;

    if (cmp(hex_data, "88\0"))   return 0x88;

    if (cmp(hex_data, "89\0"))   return 0x89;

    if (cmp(hex_data, "8A\0"))   return 0x8A;

    if (cmp(hex_data, "8B\0"))   return 0x8B;

    if (cmp(hex_data, "8C\0"))   return 0x8C;

    if (cmp(hex_data, "8D\0"))   return 0x8D;

    if (cmp(hex_data, "8E\0"))   return 0x8E;

    if (cmp(hex_data, "8F\0"))   return 0x8F;

    if (cmp(hex_data, "90\0"))   return 0x90;

    if (cmp(hex_data, "91\0"))   return 0x91;

    if (cmp(hex_data, "92\0"))   return 0x92;

    if (cmp(hex_data, "93\0"))   return 0x93;

    if (cmp(hex_data, "94\0"))   return 0x94;

    if (cmp(hex_data, "95\0"))   return 0x95;

    if (cmp(hex_data, "96\0"))   return 0x96;

    if (cmp(hex_data, "97\0"))   return 0x97;

    if (cmp(hex_data, "98\0"))   return 0x98;

    if (cmp(hex_data, "99\0"))   return 0x99;

    if (cmp(hex_data, "9A\0"))   return 0x9A;

    if (cmp(hex_data, "9B\0"))   return 0x9B;

    if (cmp(hex_data, "9C\0"))   return 0x9C;

    if (cmp(hex_data, "9D\0"))   return 0x9D;

    if (cmp(hex_data, "9E\0"))   return 0x9E;

    if (cmp(hex_data, "9F\0"))   return 0x9F;

    if (cmp(hex_data, "A0\0"))   return 0xA0;

    if (cmp(hex_data, "A1\0"))   return 0xA1;

    if (cmp(hex_data, "A2\0"))   return 0xA2;

    if (cmp(hex_data, "A3\0"))   return 0xA3;

    if (cmp(hex_data, "A4\0"))   return 0xA4;

    if (cmp(hex_data, "A5\0"))   return 0xA5;

    if (cmp(hex_data, "A6\0"))   return 0xA6;

    if (cmp(hex_data, "A7\0"))   return 0xA7;

    if (cmp(hex_data, "A8\0"))   return 0xA8;

    if (cmp(hex_data, "A9\0"))   return 0xA9;

    if (cmp(hex_data, "AA\0"))   return 0xAA;

    if (cmp(hex_data, "AB\0"))   return 0xAB;

    if (cmp(hex_data, "AC\0"))   return 0xAC;

    if (cmp(hex_data, "AD\0"))   return 0xAD;

    if (cmp(hex_data, "AE\0"))   return 0xAE;

    if (cmp(hex_data, "AF\0"))   return 0xAF;

    if (cmp(hex_data, "B0\0"))   return 0xB0;

    if (cmp(hex_data, "B1\0"))   return 0xB1;

    if (cmp(hex_data, "B2\0"))   return 0xB2;

    if (cmp(hex_data, "B3\0"))   return 0xB3;

    if (cmp(hex_data, "B4\0"))   return 0xB4;

    if (cmp(hex_data, "B5\0"))   return 0xB5;

    if (cmp(hex_data, "B6\0"))   return 0xB6;

    if (cmp(hex_data, "B7\0"))   return 0xB7;

    if (cmp(hex_data, "B8\0"))   return 0xB8;

    if (cmp(hex_data, "B9\0"))   return 0xB9;

    if (cmp(hex_data, "BA\0"))   return 0xBA;

    if (cmp(hex_data, "BB\0"))   return 0xBB;

    if (cmp(hex_data, "BC\0"))   return 0xBC;

    if (cmp(hex_data, "BD\0"))   return 0xBD;

    if (cmp(hex_data, "BE\0"))   return 0xBE;

    if (cmp(hex_data, "BF\0"))   return 0xBF;

    if (cmp(hex_data, "C0\0"))   return 0xC0;

    if (cmp(hex_data, "C1\0"))   return 0xC1;

    if (cmp(hex_data, "C2\0"))   return 0xC2;

    if (cmp(hex_data, "C3\0"))   return 0xC3;

    if (cmp(hex_data, "C4\0"))   return 0xC4;

    if (cmp(hex_data, "C5\0"))   return 0xC5;

    if (cmp(hex_data, "C6\0"))   return 0xC6;

    if (cmp(hex_data, "C7\0"))   return 0xC7;

    if (cmp(hex_data, "C8\0"))   return 0xC8;

    if (cmp(hex_data, "C9\0"))   return 0xC9;

    if (cmp(hex_data, "CA\0"))   return 0xCA;

    if (cmp(hex_data, "CB\0"))   return 0xCB;

    if (cmp(hex_data, "CC\0"))   return 0xCC;

    if (cmp(hex_data, "CD\0"))   return 0xCD;

    if (cmp(hex_data, "CE\0"))   return 0xCE;

    if (cmp(hex_data, "CF\0"))   return 0xCF;

    if (cmp(hex_data, "D0\0"))   return 0xD0;

    if (cmp(hex_data, "D1\0"))   return 0xD1;

    if (cmp(hex_data, "D2\0"))   return 0xD2;

    if (cmp(hex_data, "D3\0"))   return 0xD3;

    if (cmp(hex_data, "D4\0"))   return 0xD4;

    if (cmp(hex_data, "D5\0"))   return 0xD5;

    if (cmp(hex_data, "D6\0"))   return 0xD6;

    if (cmp(hex_data, "D7\0"))   return 0xD7;

    if (cmp(hex_data, "D8\0"))   return 0xD8;

    if (cmp(hex_data, "D9\0"))   return 0xD9;

    if (cmp(hex_data, "DA\0"))   return 0xDA;

    if (cmp(hex_data, "DB\0"))   return 0xDB;

    if (cmp(hex_data, "DC\0"))   return 0xDC;

    if (cmp(hex_data, "DD\0"))   return 0xDD;

    if (cmp(hex_data, "DE\0"))   return 0xDE;

    if (cmp(hex_data, "DF\0"))   return 0xDF;

    if (cmp(hex_data, "E0\0"))   return 0xE0;

    if (cmp(hex_data, "E1\0"))   return 0xE1;

    if (cmp(hex_data, "E2\0"))   return 0xE2;

    if (cmp(hex_data, "E3\0"))   return 0xE3;

    if (cmp(hex_data, "E4\0"))   return 0xE4;

    if (cmp(hex_data, "E5\0"))   return 0xE5;

    if (cmp(hex_data, "E6\0"))   return 0xE6;

    if (cmp(hex_data, "E7\0"))   return 0xE7;

    if (cmp(hex_data, "E8\0"))   return 0xE8;

    if (cmp(hex_data, "E9\0"))   return 0xE9;

    if (cmp(hex_data, "EA\0"))   return 0xEA;

    if (cmp(hex_data, "EB\0"))   return 0xEB;

    if (cmp(hex_data, "EC\0"))   return 0xEC;

    if (cmp(hex_data, "ED\0"))   return 0xED;

    if (cmp(hex_data, "EE\0"))   return 0xEE;

    if (cmp(hex_data, "EF\0"))   return 0xEF;

    if (cmp(hex_data, "F0\0"))   return 0xF0;

    if (cmp(hex_data, "F1\0"))   return 0xF1;

    if (cmp(hex_data, "F2\0"))   return 0xF2;

    if (cmp(hex_data, "F3\0"))   return 0xF3;

    if (cmp(hex_data, "F4\0"))   return 0xF4;

    if (cmp(hex_data, "F5\0"))   return 0xF5;

    if (cmp(hex_data, "F6\0"))   return 0xF6;

    if (cmp(hex_data, "F7\0"))   return 0xF7;

    if (cmp(hex_data, "F8\0"))   return 0xF8;

    if (cmp(hex_data, "F9\0"))   return 0xF9;

    if (cmp(hex_data, "FA\0"))   return 0xFA;

    if (cmp(hex_data, "FB\0"))   return 0xFB;

    if (cmp(hex_data, "FC\0"))   return 0xFC;

    if (cmp(hex_data, "FD\0"))   return 0xFD;

    if (cmp(hex_data, "FE\0"))   return 0xFE;

    if (cmp(hex_data, "FF\0"))   return 0xFF;
}

static unsigned char cmp(const void *dest, const void *src) {
    const unsigned char *Dest = (const unsigned char *) dest;
    const unsigned char *Src = (const unsigned char *) src;

    if (len(Dest) != len(Src)) return 0;

    unsigned long LengthDest = 0;
    unsigned long Index = 0;

    for (; *(Dest + LengthDest) != '\0'; ++LengthDest) {
        if (*(Dest + LengthDest) == *(Src + Index)) {
            ++Index;
        }
    }

    if (Index == LengthDest) {
        return 1;
    }

    else {
        return 0;
    }
}


static int find(const void *buffer, const void *buffer_search) {
    const unsigned char *Buffer = (const unsigned char *) buffer;
    const unsigned char *Buffer_Search = (const unsigned char *) buffer_search;


    unsigned int Length_Search = len(Buffer_Search);

    for (int Search = 0; *(Buffer + Search); ++Search)  {
        if (*(Buffer + Search) == *(Buffer_Search + 0) && *(Buffer + (Search + (Length_Search - 1))) == *(Buffer_Search + (Length_Search - 1))) {
            unsigned int LengthCheck = 0;

            for (unsigned int Checking = Search, Read = 0; Read < Length_Search; ++Checking, ++Read) {
                if (*(Buffer + Checking) == *(Buffer_Search + Read)) ++LengthCheck;
            }

            if (LengthCheck == Length_Search) return Search;
        }
    }

    return -1;
}


static int find_index(const void *buffer, const void *buffer_search, unsigned int position) {
    const unsigned char *Buffer = (const unsigned char *) buffer;
    const unsigned char *Buffer_Search = (const unsigned char *) buffer_search;

    unsigned int Length_Search = len(Buffer_Search);

    for (int Search = position; *(Buffer + Search); ++Search)  {
        if (*(Buffer + Search) == *(Buffer_Search + 0) && *(Buffer + (Search + (Length_Search - 1))) == *(Buffer_Search + (Length_Search - 1))) {
            unsigned int LengthCheck = 0;

            for (unsigned int Checking = Search, Read = 0; Read < Length_Search; ++Checking, ++Read) {
                if (*(Buffer + Checking) == *(Buffer_Search + Read)) ++LengthCheck;
            }

            if (LengthCheck == Length_Search) return Search;
        }
    }

    return -1;
}

static void DeleteBuffer(void *buffer, const void *buffer_delete) {
    unsigned char *Buffer = (unsigned char *) buffer;
    unsigned char *Buffer_Delete = (unsigned char *) buffer_delete;


    unsigned int LengthBuf = len(Buffer);
    unsigned int LengthBuf_Del = len(Buffer_Delete);
    int Offset_Del = 0;

    char Buffer_Temp[LengthBuf];
    ZeroBuffer(Buffer_Temp, LengthBuf);

    CopyBuffer(Buffer_Temp, Buffer);
    ClearBuffer(Buffer);

    Offset_Del = find_index(Buffer_Temp, Buffer_Delete, Offset_Del);

    for (unsigned int Iter = 0; Iter < LengthBuf; ++Iter) {
        if (Offset_Del != -1) {
            if (Iter == Offset_Del) {
                Iter += LengthBuf_Del;
                ++Offset_Del;

                Offset_Del = find_index(Buffer_Temp, Buffer_Delete, Offset_Del);
            }
        }

        Append(Buffer, Buffer_Temp[Iter]);
    }
}

#ifdef _WINSOCK2API_
const char *gethost_ip(const char *host) {
    struct hostent *ip = gethostbyname(host);
    return (const char *) inet_ntoa(*((struct in_addr *) ip->h_addr_list[0]));
}
#endif

#ifdef _INET_H_
const char *gethost_ip(const char *host) {
    struct hostent *ip = gethostbyname(host);
    return (const char *) inet_ntoa(*((struct in_addr *) ip->h_addr_list[0]));
}
#endif
