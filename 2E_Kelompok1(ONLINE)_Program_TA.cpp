#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

string nama, norek, isiQueue[100], input_trans[1000];
int password, i, passkey, saldo_awal, saldo_akhir, saldo_tarik[100], new_pass, trans_ops, cetak, inp_rek, pilih_dafbank, lanjut, bukti_s, choose_ops, trans, back_menu;
int input_data;
int jumlah = -1;
time_t t = time(NULL);
tm* tPtr = localtime(&t);

bool IsEmpty()
{
    return jumlah == -1;
}

void Enqueue()
{
    for (auto i = 1; i <= input_data; i++)
    {
        jumlah += 1;
        isiQueue[jumlah] = input_trans[i];
    }
}

int cancel()
{
    cout << "\n\n\n   TERIMA KASIH TELAH MENGGUNAKAN\n"
         << "          LAYANAN KAMI\n"
         << "------------------------------------\n"
         << "  THANK YOU FOR USING OUR SERVICES\n";
    exit (0);
}

void kertas_Print_hed_id()
{
    cout << "\n\n\n\n\n\nPT PAKUAN KARYA MANDIRI TBK\n"
         << "TANGGAL        WAKTU\n"
         << (tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900 << "        " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<< endl << endl
         << "LOKASI  :  UNIVERSITAS PAKUAN 1\n\n\n";
}

void kertas_Print_hed_en()
{
    cout << "\n\n\n\n\n\nPT PAKUAN KARYA MANDIRI TBK\n"
         << " DATE          TIME\n"
         << (tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900 << "        " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<< endl << endl;
}

void kertas_Print_bot_id()
{
    cout << "\n\n\n\nSIMPAN TANDA TERIMA INI\n"
         << "SEBAGAI BUKTI TRANSAKSI YANG SAH\n";
}

void kertas_Print_bot_en()
{
    cout << "\n\n\n\nKEEP THIS AUTOGRAPH\n"
         << "AS A VALID EVIDENCE OF TRANSACTION\n";
    exit(0);
}

void passkey_id(int chance)
{
    for (int i = chance; i > chance-1 ; --i)
    {
        if (i == 0)
        {
            cout << "      REKENING ANDA TELAH DIBLOKIR      \n"
                 << "SILAHKAN MELANJUTKAN TRANSAKSI DI TELLER\n";
            cancel();
        }
        else
        {
            cout << "MASUKKAN PIN ATM ANDA\n"; cin >> password;
            if (password == passkey)
            {
                i = 0;
            }   
            else 
            {
                cout << "\nANDA MEMILIKI KESEMPATAN " << i-1 << " KALI LAGI UNTUK MEMASUKAN PIN\n";
                passkey_id(i-1);
            }
        }
    }
}

void passkey_en(int chance)
{
    for (int i = chance; i > chance-1 ; --i)
    {
        if (i == 0)
        {
            cout << "   YOUR ACCOUNT NUMBER HAS BEEN BLOCKED   \n"
                 << "PLEASE CONTINUE YOUR TRANSACTION TO TELLER\n";
            cancel();
        }
        else
        {
            cout << "INPUT YOUR ATM PIN\n"; cin >> password;
            if (password == passkey)
            {
                i = 0;
            }   
            else 
            {
                cout << "\nYOU HAVE " << i-1 << " CHANCES LEFT TO INSERT YOUR PIN\n";
                passkey_id(i-1);
            }
        }
    }
}

void time_tdy_id()
{
    cout << "SELAMAT ";
    if ((tPtr->tm_hour >= 0 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 11))
        cout << "PAGI, ";

    else if ((tPtr->tm_hour >= 11 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 15))
        cout << "SIANG, ";

    else if ((tPtr->tm_hour >= 15 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 19))
        cout << "SORE, ";
    
    else if ((tPtr->tm_hour >= 19 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 0))
        cout << "MALAM, ";
    cout << nama << endl << endl;
}

void time_tdy_en()
{
    cout << "GOOD ";
    if ((tPtr->tm_hour >= 0 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 11))
        cout << "MORNIMG, ";

    else if ((tPtr->tm_hour >= 11 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 15))
        cout << "AFTERNOON, ";

    else if ((tPtr->tm_hour >= 15 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 19))
        cout << "EVENING, ";
    
    else if ((tPtr->tm_hour >= 19 && tPtr->tm_min >= 1) && (tPtr->tm_hour <= 0))
        cout << "NIGHT, ";
    cout << nama << endl << endl;
}

void per_key_id(int chance)
{
    for (int i = chance; i > chance-1 ; --i)
    {
        cout << "SILAHKAN KETIK PIN BARU ANDA\n"
             << "UNTUK MENINGKATKAN KEAMANAN,\n"
             << " PASTIKAN ANDA MENGGUNAKAN\n"
             << "        PIN 6 DIGIT\n\n"
             << "SETELAH SELESAI-TEKAN ENTER\n\n\n";
        cin >> new_pass;
        cout << "\n\n\n\nTEKAN ANGKA 3 UNTUK PEMBATALAN";
        if (new_pass == passkey)
        {
            cout << "ANDA MEMASUKAN PIN LAMA ANDA\n";
            per_key_id(i-1);
        }
        else if (new_pass == 3)
        {
            cancel();
        }
        else
        {
            new_pass = passkey;
            cout << "    GANTI PIN SELESAI SILAHKAN AMBIL\n"
                 << "       SILAHKAN AMBIL KARTU ANDA\n";
            cancel();
        }
    }
}

void per_key_en(int chance)
{
    for (int i = chance; i > chance-1 ; --i)
    {
        cout << " PLEASE TYPE YOUR NEW PIN\n"
             << "  TO IMPROVING SECURITY,\n"
             << "    MAKE SURE YOU USE\n"
             << "       6 DIGIT-PIN\n\n"
             << "AFTER COMPLETED-PRESS ENTER\n\n\n";
        cin >> new_pass;
        cout << "\n\n\n\nPRESS NUMBER 3 FOR CANCELITION";
        if (new_pass == passkey)
        {
            cout << "YOUR INPUTED YOUR OLD PIN\n";
            per_key_id(i-1);
        }
        else if (new_pass == 3)
        {
            cancel();
        }
        else
        {
            new_pass = passkey;
            cout << "       CHANGING PIN FINISHED         \n"
                 << "       PLEASE TAKE YOUR CARD         \n";
            cancel();
        }
    }
}

void ganti_pin_id()
{
    passkey_id(3);
    per_key_id(3);
}

void ganti_pin_en()
{
    passkey_en(3);
    per_key_en(3);
}

void ops_tarik_tun()
{
    saldo_akhir = saldo_awal - saldo_tarik[i];
}

void info_tar_saldo_id()
{
    cout << "PENARIKAN TUNAI\n"
         << "NO. KARTU     : " << norek
         << "\nJUMLAH        : RP. " << saldo_tarik[i]
         << "\nSALDO TERSISA : RP. " << saldo_akhir;
}

void info_tar_saldo_en()
{
    cout << "WITHDRAWL CASH\n"
         << "NUMBER CARD      : " << norek
         << "\nTOTAL            : " << saldo_tarik[i]
         << "\nLEFTOVER BALANCE : " << saldo_akhir;
}

void ops_ambil_duit_id()
{
    kertas_Print_hed_id();
    info_tar_saldo_id();
    kertas_Print_bot_id();
}

void ops_ambil_duit_en()
{
    kertas_Print_hed_en();
    info_tar_saldo_en();
    kertas_Print_bot_en();
}

void info_saldo_print_id()
{
    kertas_Print_hed_id();
    cout << "SALDO REKENING\n"
         << "SALDO : " << saldo_awal;
    kertas_Print_bot_id();
}

void info_saldo_print_en()
{
    kertas_Print_hed_en();
    cout << "ACCOUNT NUMBER BALANCE\n"
         << "BALANCE : " << saldo_awal;
    kertas_Print_bot_en();
}

void daftar_bank()
{
    cout << "BANK BRI                                        002\n"
         << "BANK EKSPOR INDONESIA       			         003\n"
         << "BANK MANDIRI                                    008\n"
         << "BANK BNI                                        009\n"
         << "BANK DANAMON                                    011\n"
         << "PERMATA BANK                                    013\n"
         << "BANK BCA                                        014\n"
         << "BANK BII MAYBANK                                016\n"
         << "BANK PANIN                                      019\n"
         << "BANK ARTA NIAGA KENCANA                         020\n"
         << "BANK CIMB NIAGA                                 022\n"
         << "BANK CIMB NIAGA SYARIAH                         022\n"
         << "BANK UOB INDONESIA                              023\n"
         << "BANK OCBC NISP                                  028\n"
         << "AMERICAN EXPRESS BANK LTD                       030\n"
         << "CITIBANK                                        031\n"
         << "CITIBANK N.A                                    031\n" 
         << "JP. MORGAN CHASE BANK, N.A                      032\n"
         << "BANK OF AMERICA, N.A                            033\n"
         << "ING INDONESIA BANK                              034\n"
         << "BANK ARTHA GRAHA INTERNASIONAL                  037\n"
         << "BANK CREDIT AGRICOLE INDOSUEZ                   039\n"
         << "THE BANGKOK BANK COMP. LTD                      040\n"
         << "THE HONGKONG & SHANGHAI B.C. (BANK HSBC)        041\n"
         << "THE BANK OF TOKYO MITSUBISHI UFJ LTD            042\n"
         << "BANK SUMITOMO MITSUI INDONESIA                  045\n"
         << "BANK DBS INDONESIA                              046\n"
         << "BANK RESONA PERDANIA                            047\n"
         << "BANK MIZUHO INDONESIA                           048\n" 
         << "STANDARD CHARTERED BANK                         050\n"
         << "BANK ABN AMRO                                   052\n"
         << "BANK KEPPEL TATLEE BUANA                        053\n"
         << "BANK CAPITAL INDONESIA                          054\n"
         << "BANK BNP PARIBAS INDONESIA                      057\n"
         << "KOREA EXCHANGE BANK DANAMON                     059\n"
         << "BANK ANZ INDONESIA                              061\n"
         << "DEUTSCHE BANK AG.                               067\n"
         << "BANK WOORI INDONESIA                            068\n"
         << "BANK OF CHINA                                   069\n"
         << "BANK BUMI ARTA                                  076\n"
         << "BANK EKONOMI                                    087\n"
         << "BANK ANTARDAERAH                                088\n"
         << "BANK HAGA                                       089\n"
         << "BANK IFI                                        093\n"
         << "BANK JTRUST                                     095\n"
         << "BANK MAYAPADA                                   097\n"
         << "BANK JABAR DAN BANTEN (BJB)                     110\n"
         << "BANK DKI                                        111\n"
         << "BPD DIY                                         112\n"
         << "BANK JATENG                                     113\n"
         << "BANK JATIM                                      114\n"
         << "BPD JAMBI                                       115\n"
         << "BPD ACEH, BPD ACEH SYARIAH                      116\n"
         << "BANK SUMUT                                      117\n"
         << "BANK NAGARI                                     118\n"
         << "BANK RIAU                                       119\n"
         << "BANK SUMSEL BABEL                               120\n"
         << "BANK LAMPUNG                                    121\n"
         << "BANK KALSEL (KALIMANTAN SELATAN)                122\n"
         << "BANK KALBAR (KALIMANTAN BARAT)                  123\n"
         << "BANK KALTIMTARA (KALIMANTAN TIMUR DAN UTARA)    124\n"
         << "BANK KALTENG (KALIMANTAN TENGAH)                125\n"
         << "BANK SULSELBAR (SULAWESI SELATAN DAN BARAT)     126\n"
         << "BANK SULUTGO (SULAWESI UTARA DAN GORONTALO)     127\n"
         << "BANK NTB, NTB SYARIAH                           128\n"
         << "BPD BALI                                        129\n"
         << "BANK NTT                                        130\n"
         << "BANK MALUKU MALUT                               131\n"
         << "BANK PAPUA                                      132\n"
         << "BANK BENGKULU                                   133\n"
         << "BANK SULTENG (SULAWESI TENGAH)                  134\n"
         << "BANK SULTRA                                     135\n"
         << "BANK NUSANTARA PARAHYANGAN                      145\n"
         << "BANK OF INDIA INDONESIA                         146\n"
         << "BANK MUAMALAT                                   147\n"
         << "BANK MESTIKA DHARMA                             151\n"
         << "BANK METRO EXPRESS (BANK SHINHAN INDONESIA)     152\n"
         << "BANK SINARMAS                                   153\n"
         << "BANK MASPION INDONESIA                          157\n"
         << "BANK HAGAKITA                                   159\n"
         << "BANK GANESHA                                    161\n"
         << "BANK WINDU KENTJANA                             162\n"
         << "HALIM INDONESIA BANK (BANK ICBC INDONESIA)      164\n"
         << "BANK HARMONI INTERNATIONAL                      166\n"
         << "BANK QNB KESAWAN (BANK QNB INDONESIA)           167\n"
         << "BANK TABUNGAN NEGARA (BTN)                      200\n"
         << "BANK HIMPUNAN SAUDARA 1906                      212\n"
         << "BANK TABUNGAN PENSIUNAN NASIONAL (BTPN)         213\n"
         << "JENIUS                                          213\n"
         << "BANK SWAGUNA                                    405\n"
         << "BANK SYARIAH INDONESIA (EKS BRI SYARIAH)        422\n"
         << "BANK BJB SYARIAH                                425\n"
         << "BANK MEGA                                       426\n"
         << "BANK SYARIAH INDONESIA (EKS BNI SYARIAH)        427\n"
         << "BANK BUKOPIN                                    441\n"
         << "BANK SYARIAH INDONESIA (EKS MANDIRI SYARIAH)    451\n"
         << "BANK BISNIS INTERNASIONAL                       459\n"
         << "BANK SRI PARTHA                                 466\n"
         << "BANK JASA JAKARTA                               472\n"
         << "BANK BINTANG MANUNGGAL                          484\n"
         << "BANK MNC / BANK BUMIPUTERA                      485\n"
         << "BANK YUDHA BHAKTI                               490\n"
         << "BANK BRI AGRO                                   494\n"
         << "BANK INDOMONEX (BANK SBI INDONESIA)             498\n"
         << "BANK ROYAL INDONESIA                            501\n"
         << "BANK ALFINDO (BANK NATIONAL NOBU)               503\n"
         << "BANK SYARIAH MEGA                               506\n"
         << "BANK INA PERDANA                                513\n"
         << "BANK HARFA                                      517\n"
         << "PRIMA MASTER BANK                               520\n"
         << "BANK PERSYARIKATAN INDONESIA                    521\n"
         << "BANK DIPO INTERNATIONAL (BANK SAHABAT SAMPOERNA)523\n"
         << "BANK AKITA                                      525\n"
         << "LIMAN INTERNATIONAL BANK                        526\n"
         << "ANGLOMAS INTERNASIONAL BANK                     531\n"
         << "BANK KESEJAHTERAAN EKONOMI                      535\n"
         << "BANK BCA SYARIAH                                536\n"
         << "BANK ARTOS IND                                  542\n"
         << "BANK PURBA DANARTA                              547\n"
         << "BANK MULTI ARTA SENTOSA                         548\n"
         << "BANK MAYORA INDONESIA                           553\n"
         << "BANK INDEX SELINDO                              555\n"
         << "CENTRATAMA NASIONAL BANK                        559\n"
         << "BANK FAMA INTERNASIONAL                         562\n"
         << "BANK MANDIRI TASPEN POS                         564\n"
         << "BANK VICTORIA INTERNATIONAL                     566\n"
         << "BANK HARDA                                      567\n"
         << "BPR KS                                          688\n"
         << "BANK COMMONWEALTH                               950\n"
         << "BANK AGRIS                                      945\n"
         << "BANK MERINCORP                                  946\n"
         << "BANK MAYBANK INDOCORP                           947\n"
         << "BANK OCBC – INDONESIA                           948\n"
         << "BANK CTBC (CHINA TRUST) INDONESIA               949\n\n\n\n\n";
}

void print_trans_id()
{
    cout << "\nNAMA PENGIRIM  : " << nama 
         << "\nNO. REKENING   : " << norek
         << "\nTRANSFER       : RP. " << saldo_tarik[i]
         << "\nSALDO REK      : RP. " << saldo_akhir;
}

void print_trans_en()
{
    cout << "\nSENDER NAME    : " << nama
         << "\nACCOUNT NUMBER : " << norek
         << "\nTRANSFER       : RP. " << saldo_tarik[i]
         << "\nTOTAL BALANCE  : RP. " << saldo_awal;
}

void menu_id(int test)
{
    for (int i = test; i > test-1 ; --i)
    {
        time_tdy_id();
        cout << "         PT PAKUAN KARYA MANDIRI TBK\n\n"
             << "     SILAHKAN PILIH JUMLAH PENARIKAN UANG\n\n\n"
             << "1. 2.000.000                       100.000  .8\n\n"
             << "2. 3.000.000                       500.000  .7\n\n"
             << "3. JUMLAH LAINNYA                1.000.000  .6\n\n"
             << "4. TRANSAKSI LAINNYA             1.500.000  .5\n\n"
             << "PILIH (1-8) : ";
        cin >> choose_ops;
        switch (choose_ops)
        {
        case 1:
            saldo_tarik[i] = 2000000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;
        
        case 2:
            saldo_tarik[i] = 3000000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;
            
        case 3:
            cout << "    MASUKKAN JUMLAH PENARIKAN\n"
                 << "   DALAM KELIPATAN RP. 50.000\n"
                 << "MAKSIMUM PENARIKAN RP. 12.500.000\n\n\n";
            cin >> saldo_tarik[i];
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
                cout << "\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                     << "     APAKAH ANDA INGIN MELAKUKAN\n"
                     << "         TRANSAKSI LAINNYA ?    \n\n\n"
                     << "                           YA .1\n\n"
                     << "                        TIDAK .2\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(1);
                }
                else
                {
                    cancel();
                }
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;

        case 4:
            cout << "       SILAHKAN MEMILIH JENIS TRANSAKSI\n\n\n"
                 << "1. GANTI PIN             RIWAYAT TRANSAKSI .5\n\n"
                 << "2. TARIK TUNAI                    TRANSFER .4\n\n"
                 << "3. INFORMASI\n\n"
                 << "PILIH (1-5) : ";
            cin >> trans_ops;
            switch (trans_ops)
            {
            case 1:
                ganti_pin_id();
                break;
    
            case 2:
                cout << "    MASUKKAN JUMLAH PENARIKAN\n"
                     << "   DALAM KELIPATAN RP. 50.000\n"
                     << "MAKSIMUM PENARIKAN RP. 12.500.000\n\n\n";
                cin >> saldo_tarik[i];
                ops_tarik_tun();
                if (saldo_akhir > 0)
                {
                    ops_ambil_duit_id();
                }
                else
                {
                    cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                    cancel();
                }
                break;
    
            case 3:
                cout << "INFORMASI SALDO YANG AKAN DITAMPILKAN\n\n\n"
                     << "DITAMPILKAN PADA LAYAR .1\n\n"
                     << "DITAMPILKAN PADA RECIPT .2\n\n"
                     << "PILIH (1/2) : ";
                cin >> bukti_s;
                switch (bukti_s)
                {
                case 1:
                    cout << "SALDO REKENING ANDA\n\n\n\n r"
                         << saldo_awal 
                         << "\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                         << "     APAKAH ANDA INGIN MELAKUKAN\n"
                         << "         TRANSAKSI LAINNYA ?    \n\n\n"
                         << "                           YA .1\n\n"
                         << "                        TIDAK .2\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        input_data += 1;
                        saldo_awal = saldo_akhir;
                        menu_id(1);
                    }
                    else
                    {
                        cancel();
                    }
                break;     
                case 2:
                    info_saldo_print_en();
                    break;
                }        
                break;
            case 4:
                cout << "       SILAHKAN PILIH TUJUAN       \n"
                     << "          TRANSFER ANDA\n\n\n\n"
                     << "                     TRANSFER KE .1\n"
                     << "                     BANK PAKUAN\n\n"
                     << "                     TRANSFER KE .2\n"
                     << "                       BANK LAIN\n\n"
                     << "PILIH (1/2) : "; cin >> trans;
                switch (trans)
                {
                case 1:
                    input_trans[i] = "TRANSFER KE BANK PAKUAN";
                    cout << "    TRANSFER KE BANK PAKUAN\n"    
                         << "      MASUKKAN NO.REKENING\n"
                         << "             TUJUAN\n\n\n\n\n";
                    cin >> inp_rek;
                    cout << endl << endl << endl << endl << endl << endl
                         << "     SILAHKAN MASUKKAN JUMLAH\n"
                         << "      YANG AKAN DI TRANSFER\n\n\n\n\n";
                    cin >> saldo_tarik[i];
                    cout << "     APAKAH ANDA YAKIN UNTUK\n"
                         << "     MELANJUTKAN TRANSAKSI?\n\n"
                         << "            TEKAN 1 JIKA YA ------>\n\n"
                         << "            TEKAN 2 JIKA TIDAK --->\n\n"
                         << "PILIH (1/2) : "; cin >> lanjut;
                    switch (lanjut)
                    {
                    case 1:
                        ops_tarik_tun();
                        kertas_Print_hed_id();
                        cout << "TRANSFER KE BANK PAKUAN";
                        print_trans_id();
                        kertas_Print_bot_id();
                        cout << "\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                                 << "     APAKAH ANDA INGIN MELAKUKAN\n"
                                 << "         TRANSAKSI LAINNYA ?    \n\n\n"
                                 << "                           YA .1\n\n"
                                 << "                        TIDAK .2\n\n";
                            cin >> back_menu;
                            if (back_menu == 1)
                            {
                                input_data += 1;
                                saldo_awal = saldo_akhir;
                                menu_id(1);
                            }
                            else
                            {
                                cancel();
                            }
                        break;
                    case 2:
                        cancel();
                        break;
                    }
                    break;
                
                case 2:
                    input_trans[i] = "TRANSFER ANTAR BANK";
                    cout << "      PERLU MELIHAT KODE BANK?     \n"
                    << " KARENA UNTUK TRANSFER AKAN DIMULAI\n" 
                    << " DARI KODE BANK 3 DIGIT DIAWAL, DAN\n"
                    << "     DIIKUTI NO.REKENING\n\n\n\n\n"
                    << "            TEKAN 1 JIKA YA ------>\n\n"
                    << "            TEKAN 2 JIKA TIDAK --->\n\n"
                    << "PILIH (1/2) : "; cin >> pilih_dafbank;
                    switch (pilih_dafbank)
                    {
                    case 1:
                        daftar_bank();
                        cout << "       TRANSFER ANTAR BANK\n"    
                            << "   MASUKKAN KODE BANK 3 DIGIT\n"
                            << " DIAWAL, DAN DIIKUTI NO.REKENING\n"
                            << "             TUJUAN\n\n\n\n\n";
                        cin >> inp_rek;
                        cout << endl << endl << endl << endl << endl << endl
                            << "     SILAHKAN MASUKKAN JUMLAH\n"
                            << "      YANG AKAN DI TRANSFER\n\n\n\n\n";
                        cin >> saldo_tarik[i];
                        cout << "\n\n\n\n\n     APAKAH ANDA YAKIN UNTUK    \n"
                            << "     MELANJUTKAN TRANSAKSI?\n\n"
                            << "            TEKAN 1 JIKA YA ------>\n\n"
                            << "            TEKAN 2 JIKA TIDAK --->\n\n"
                            << "PILIH (1/2) : "; cin >> lanjut;
                        switch (lanjut)
                        {
                        case 1:
                            ops_tarik_tun();
                            kertas_Print_hed_id();
                            cout << "TRANSFER ANTAR BANK";
                            print_trans_id();
                            kertas_Print_bot_id();
                            cout << "\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                                 << "     APAKAH ANDA INGIN MELAKUKAN\n"
                                 << "         TRANSAKSI LAINNYA ?    \n\n\n"
                                 << "                           YA .1\n\n"
                                 << "                        TIDAK .2\n\n";
                            cin >> back_menu;
                            if (back_menu == 1)
                            {
                                input_data += 1;
                                saldo_awal = saldo_akhir;
                                menu_id(1);
                            }
                            else
                            {
                                cancel();
                            }
                            break;
                    
                        case 2:
                            cancel();
                            break;
                        }
                        break;
                    case 2:
                        cout << "       TRANSFER ANTAR BANK\n"    
                            << "   MASUKKAN KODE BANK 3 DIGIT\n"
                            << " DIAWAL, DAN DIIKUTI NO.REKENING\n"
                            << "             TUJUAN\n\n\n\n\n";
                        cin >> inp_rek;
                        cout << endl << endl << endl << endl << endl << endl
                            << "     SILAHKAN MASUKKAN JUMLAH\n"
                            << "      YANG AKAN DI TRANSFER\n\n\n\n\n";
                        cin >> saldo_tarik[i];
                        cout << "\n\n\n\n\n     APAKAH ANDA YAKIN UNTUK    \n"
                            << "     MELANJUTKAN TRANSAKSI?\n\n"
                            << "            TEKAN 1 JIKA YA ------>\n\n"
                            << "            TEKAN 2 JIKA TIDAK --->\n\n"
                            << "PILIH (1/2) : "; cin >> lanjut;
                        switch (lanjut)
                        {
                        case 1:
                            ops_tarik_tun();
                            kertas_Print_hed_id();
                            cout << "TRANSFER ANTAR BANK";
                            print_trans_id();
                            kertas_Print_bot_id();
                            cout << "\n\n\n\n\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                                 << "     APAKAH ANDA INGIN MELAKUKAN\n"
                                 << "         TRANSAKSI LAINNYA ?    \n\n\n"
                                 << "                           YA .1\n\n"
                                 << "                        TIDAK .2\n\n";
                            cin >> back_menu;
                            if (back_menu == 1)
                            {
                                input_data += 1;
                                saldo_awal = saldo_akhir;
                                menu_id(1);
                            }
                            else
                            {
                                cancel();
                            }
                            break;
                    
                        case 2:
                            cancel();
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            
            case 5:
                cout << "\nLIST RIWAYAT TRANSAKSI\n";
                if(IsEmpty())
                {
                    cout << "BELUM ADA TRANSAKSI";
                }
                for (i = 0; i < input_data; i++)
                {
                    cout << i+1 << ". " << isiQueue[i] << endl;
                }
                cout << "\n\n\n\n\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                     << "     APAKAH ANDA INGIN MELAKUKAN\n"
                     << "         TRANSAKSI LAINNYA ?    \n\n\n"
                     << "                           YA .1\n\n"
                     << "                        TIDAK .2\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(1);
                }
                else
                {
                    cancel();
                }
                break;
            }
            break;

        case 5:
            saldo_tarik[i][i] = 1500000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
                cout << "\n\n\n\n\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                     << "     APAKAH ANDA INGIN MELAKUKAN\n"
                     << "         TRANSAKSI LAINNYA ?    \n\n\n"
                     << "                           YA .1\n\n"
                     << "                        TIDAK .2\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(1);
                }
                else
                {
                    cancel();
                }
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;

        case 6:
            saldo_tarik[i] = 1000000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
                cout << "\n\n\n\n\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                     << "     APAKAH ANDA INGIN MELAKUKAN\n"
                     << "         TRANSAKSI LAINNYA ?    \n\n\n"
                     << "                           YA .1\n\n"
                     << "                        TIDAK .2\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(1);
                }
                else
                {
                    cancel();
                }
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;

        case 7:
            saldo_tarik[i] = 500000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
                cout << "\n\n\n\n\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                     << "     APAKAH ANDA INGIN MELAKUKAN\n"
                     << "         TRANSAKSI LAINNYA ?    \n\n\n"
                     << "                           YA .1\n\n"
                     << "                        TIDAK .2\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(1);
                }
                else
                {
                    cancel();
                }
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;

        case 8:
            saldo_tarik[i] = 100000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_id();
                cout << "\n\n\n\nTRANSAKSI ANDA TELAH SELESAI\n"
                     << "     APAKAH ANDA INGIN MELAKUKAN\n"
                     << "         TRANSAKSI LAINNYA ?    \n\n\n"
                     << "                           YA .1\n\n"
                     << "                        TIDAK .2\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(1);
                }
                else
                {
                    cancel();
                }
            }
            else
            {
                cout << "SALDO ANDA TIDAK MENCUKUPI\n";
                cancel();
            }
            break;
        }
    }
}

void menu_en(int test)
{
    input_data = test;
    for (int i = test; i > test-1 ; --i)
    {
        time_tdy_id();
        cout << "         PT PAKUAN KARYA MANDIRI TBK\n\n"
             << "     CHOOSE The WITHDRAWAL AMOUNT\n\n\n"
             << "1. 2.000.000                       100.000  .8\n\n"
             << "2. 3.000.000                       500.000  .7\n\n"
             << "3. OTHER AMOUNT                  1.000.000  .6\n\n"
             << "4. OTHER TRANSACTION             1.500.000  .5\n\n"
             << "PILIH (1-8) : ";
            cin >> choose_ops;
        switch (choose_ops)
        {
        case 1:
            saldo_tarik[i] = 2000000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
                cout << "\n\n\n\n\n\n\n\n    DO YOU WISH TO CONTINUE\n"
                     << "       OTHER TRANSACTION ?    \n\n\n"
                     << "                PRESS 1 IF YES --->\n\n"
                     << "                 PRESS 2 IF NO --->\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(test+1);
                }
                else
                {
                    cancel();
                }     
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT FUNDS\n";
                cancel();
            }
            break;
        
        case 2:
            saldo_tarik[i] = 3000000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
                cout << "\n\n\n\n\n\n\n\n    DO YOU WISH TO CONTINUE\n"
                     << "       OTHER TRANSACTION ?    \n\n\n"
                     << "                PRESS 1 IF YES --->\n\n"
                     << "                 PRESS 2 IF NO --->\n\n";
                cin >> back_menu;
                if (back_menu == 1)
                {
                    input_data += 1;
                    saldo_awal = saldo_akhir;
                    menu_id(test+1);
                }
                else
                {
                    cancel();
                }     
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT FUNDS\n";
                cancel();
            }
            break;
            
        case 3:
            cout << "   INSERT THE WITHDRAWLS CASH\n"
                 << "     IN MULTIPLE RP. 50.000\n"
                 << "MAXIMUM WITHDRAWLS RP. 12.500.000\n\n\n";
            cin >> saldo_tarik[i];
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT BALANCE\n";
                cancel();
            }
            break;

        case 4:
            cout << "       CHOOSE YOUR TRANSACTION TYPE\n\n\n"
                 << "1. CHANGE PIN           HISTORY TRANSACTION .5\n\n"
                 << "2. CASH WITHDRAWAL                 TRANSFER .4\n\n"
                 << "3. INFORMATION"
                 << "CHOOSE (1-5) : ";
            cin >> trans_ops;
            switch (trans_ops)
            {
            case 1:
                ganti_pin_en();
                break;
    
            case 2:
                cout << "   INSERT THE WITHDRAWLS CASH\n"
                     << "     IN MULTIPLE RP. 50.000\n"
                     << "MAXIMUM WITHDRAWLS RP. 12.500.000\n\n\n";
                cin >> saldo_tarik[i];
                ops_tarik_tun();
                if (saldo_akhir > 0)
                {
                    ops_ambil_duit_en();
                    cout << "\n\n\n\n\n\n\n\n    DO YOU WISH TO CONTINUE\n"
                        << "       OTHER TRANSACTION ?    \n\n\n"
                        << "                PRESS 1 IF YES --->\n\n"
                        << "                 PRESS 2 IF NO --->\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        input_data += 1;
                        saldo_awal = saldo_akhir;
                        menu_id(test+1);
                    }
                    else
                    {
                        cancel();
                    }     
                }
                else
                {
                    cout << "YOU HAVE INSUFFICIENT BALANCE\n";
                    cancel();
                }
                break;
    
            case 3:
                cout << "BALANCE INFORMATION THAT WILL BE SHOW\n\n\n"
                     << "SHOW ON SCREEN .1\n\n"
                     << "SHOW ON RECIPT .2\n\n"
                     << "CHOOSE (1/2) : ";
                cin >> bukti_s;
                switch (bukti_s)
                {
                case 1:
                    cout << "YOUR ACCOUNT NUMBER BALANCE\n\n\n\n"
                         << saldo_awal 
                         << "\n\n\n\nTRANSACTION HAS BEEN COMPLETED\n"
                         << "     DO YOU WISH TO CONTINUE\n"
                         << "         OTHER TRANSACTION ?    \n\n\n"
                         << "                           Ya .1\n\n"
                         << "                        Tidak .2\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        menu_id(test+1);
                    }
                    else
                    {
                        cancel();
                    }     
                case 2:
                    info_saldo_print_en();
                    break;
                }
                break;
            break;

            case 4:
                cout << "      PLEASE SELECT YOUR\n"
                     << "     TRANSFER DESTINATION\n\n\n\n"
                     << "                       INTRABANK .1\n"
                     << "                        TRANSFER\n\n"
                     << "                       INTERBANK .2\n"
                     << "                        TRANSFER\n\n"
                     << "CHOOSE (1/2) : "; cin >> trans;
                switch (trans)
                {
                case 1:

                    cout << "       INTRABANK TRANSFER\n"    
                         << "      INPUT ACCOUNT NUMBER\n"
                         << "           DESTINATION\n\n\n\n\n";
                    cin >> inp_rek;
                    cout << endl << endl << endl << endl << endl << endl
                         << "     INPUT THE AMOUNT THAT\n"
                         << "      WILL BE TRANSFERED\n\n\n\n\n";
                    cin >> saldo_tarik[i];
                    cout << "    DO YOU WISH TO CONTINUE\n"
                         << "       THE TRANSACTION?\n\n"
                         << "                PRESS 1 IF YES --->\n\n"
                         << "                 PRESS 2 IF NO --->\n\n"
                         << "CHOOSE (1/2) : "; cin >> lanjut;
                    switch (lanjut)
                    {
                    case 1:
                        ops_tarik_tun();
                        kertas_Print_hed_en();
                        cout << "INTRABANK TRANSFER\n";
                        print_trans_en();
                        kertas_Print_bot_en();
                        cout << "TRANSACTION HAS BEEN COMPLETED\n"
                             << "DO YOU WISH TO CONTINUE\n"
                             << "        OTHER TRANSACTION ?       \n\n\n"
                             << "               PRESS 1 IF YES --->\n\n"
                             << "                PRESS 2 IF NO --->\n\n";
                            cin >> back_menu;
                            if (back_menu == 1)
                            {
                                input_data += 1;
                                saldo_awal = saldo_akhir;
                                menu_id(1);
                            }
                            else
                            {
                                cancel();
                            }
                        break;
                    
                    case 2:
                        cancel();
                        break;
                    }
                    break;
                
                case 2:
                    cout << "    SEEING THE CODE BANK FIRST?   \n\n\n\n"
                         << "               PRESS 1 IF YES --->\n\n"
                         << "               PRESS 2 IF NO ---->\n\n"
                         << "CHOOSE (1/2) : "; cin >> pilih_dafbank;
                    switch (pilih_dafbank)
                    {
                    case 1:
                        daftar_bank();
                        cout << "       INTERBANK TRANSFER\n"    
                             << "   INPUT 3 DIGIT OF CODE BANK\n"
                             << " IN THE BEGINNING, AND FOLLOWED\n"
                             << " BY ACCOUNT NUMBER DESTINATION\n\n\n\n\n";
                        cin >> inp_rek;
                        cout << endl << endl << endl << endl << endl << endl
                             << "     INPUT THE AMOUNT THAT\n"
                             << "      WILL BE TRANSFERED\n\n\n\n\n";
                        cin >> saldo_tarik[i];
                        cout << "    DO YOU WISH TO CONTINUE\n"
                             << "       THE TRANSACTION?\n\n"
                             << "                PRESS 1 IF YES --->\n\n"
                             << "                 PRESS 2 IF NO --->\n\n"
                             << "CHOOSE (1/2) : "; cin >> lanjut;
                        switch (lanjut)
                        {
                        case 1:
                            ops_tarik_tun();
                            kertas_Print_hed_en();
                            cout << "INTERBANK TRANSFER\n";
                            print_trans_en();
                            kertas_Print_bot_en();
                            cout << "TRANSACTION HAS BEEN COMPLETED\n"
                                 << "DO YOU WISH TO CONTINUE\n"
                                 << "        OTHER TRANSACTION ?       \n\n\n"
                                 << "               PRESS 1 IF YES --->\n\n"
                                 << "                PRESS 2 IF NO --->\n\n";
                                cin >> back_menu;
                                if (back_menu == 1)
                                {
                                    input_data += 1;
                                    saldo_awal = saldo_akhir;
                                    menu_id(1);
                                }
                                else
                                {
                                    cancel();
                                }     
                            break;
                            
                        case 2:
                            cancel();
                            break;
                        }
                        break;
                    
                    case 2:
                        cout << "       INTERBANK TRANSFER\n"    
                             << "   INPUT 3 DIGIT OF CODE BANK\n"
                             << " IN THE BEGINNING, AND FOLLOWED\n"
                             << " BY ACCOUNT NUMBER DESTINATION\n\n\n\n\n";
                        cin >> inp_rek;
                        cout << endl << endl << endl << endl << endl << endl
                             << "     INPUT THE AMOUNT THAT\n"
                             << "      WILL BE TRANSFERED\n\n\n\n\n";
                        cin >> saldo_tarik[i];
                        cout << "    DO YOU WISH TO CONTINUE\n"
                             << "       THE TRANSACTION?\n\n"
                             << "                PRESS 1 IF YES --->\n\n"
                             << "                 PRESS 2 IF NO --->\n\n"
                             << "CHOOSE (1/2) : "; cin >> lanjut;
                        switch (lanjut)
                        {
                        case 1:
                            ops_tarik_tun();
                            kertas_Print_hed_en();
                            cout << "INTERBANK TRANSFER\n";
                            print_trans_en();
                            kertas_Print_bot_en();
                            cout << "TRANSACTION HAS BEEN COMPLETED\n"
                                 << "DO YOU WISH TO CONTINUE\n"
                                 << "        OTHER TRANSACTION ?       \n\n\n"
                                 << "               PRESS 1 IF YES --->\n\n"
                                 << "                PRESS 2 IF NO --->\n\n";
                                cin >> back_menu;
                                if (back_menu == 1)
                                {
                                    input_data += 1;
                                    saldo_awal = saldo_akhir;
                                    menu_id(1);
                                }
                                else
                                {
                                    cancel();
                                }     
                            break;
                        
                        case 2:
                            cancel();
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            case 5: 
                cout << "\nLIST HISTORY TRANSACTION\n";
                if (IsEmpty())
                {
                    cout << "NO TRANSACTION";
                }
                for (i = 0; i < input_data; i++)
                {
                    cout << i+1 << ". " << isiQueue[i] << endl;
                }
                cout << endl << endl
                     << "TRANSACTION HAS BEEN COMPLETED\n"
                     << "DO YOU WISH TO CONTINUE\n"
                     << "        OTHER TRANSACTION ?       \n\n\n"
                     << "               PRESS 1 IF YES --->\n\n"
                     << "                PRESS 2 IF NO --->\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        input_data += 1;
                        saldo_awal = saldo_akhir;
                        menu_id(1);
                    }
                    else
                    {
                        cancel();
                    }     
                break;
            }
            break;

        case 5:
            saldo_tarik[i] = 1500000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT FUNDS\n";
                cancel();
            }
            break;

        case 6:
            saldo_tarik[i] = 1000000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
                cout << "TRANSACTION HAS BEEN COMPLETED\n"
                     << "DO YOU WISH TO CONTINUE\n"
                     << "        OTHER TRANSACTION ?       \n\n\n"
                     << "               PRESS 1 IF YES --->\n\n"
                     << "                PRESS 2 IF NO --->\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        input_data += 1;
                        saldo_awal = saldo_akhir;
                        menu_id(1);
                    }
                    else
                    {
                        cancel();
                    }
                 break;
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT FUNDS\n";
                cancel();
            }
            break;

        case 7:
            saldo_tarik[i] = 500000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
                cout << "TRANSACTION HAS BEEN COMPLETED\n"
                     << "DO YOU WISH TO CONTINUE\n"
                     << "        OTHER TRANSACTION ?       \n\n\n"
                     << "               PRESS 1 IF YES --->\n\n"
                     << "                PRESS 2 IF NO --->\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        input_data += 1;
                        saldo_awal = saldo_akhir;
                        menu_id(1);
                    }
                    else
                    {
                        cancel();
                    }
                 break;
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT FUNDS\n";
                cancel();
            }
            break;

        case 8:
            saldo_tarik[i] = 100000;
            ops_tarik_tun();
            if (saldo_akhir > 0)
            {
                ops_ambil_duit_en();
                cout << "TRANSACTION HAS BEEN COMPLETED\n"
                     << "DO YOU WISH TO CONTINUE\n"
                     << "        OTHER TRANSACTION ?       \n\n\n"
                     << "               PRESS 1 IF YES --->\n\n"
                     << "                PRESS 2 IF NO --->\n\n";
                    cin >> back_menu;
                    if (back_menu == 1)
                    {
                        input_data += 1;
                        saldo_awal = saldo_akhir;
                        menu_id(1);
                    }
                    else
                    {
                        cancel();
                    }
                 break;
            }
            else
            {
                cout << "YOU HAVE INSUFFICIENT FUNDS\n";
                cancel();
            }
            break;
        }
    }
}

void main_ops_id()
{
    passkey_id(3);
    menu_id(1);
}

void main_ops_en()
{
    passkey_en(3);
    menu_en(1);
}

int main()
{
    int pref_lang;
    cout << "----------------------------------------\n"
         << "        SIMULASI PENGGUNAAN ATM\n"
         << "----------------------------------------\n";
    cout << "Masukkan Nama Nasabah                       : "; getline(cin, nama);
    cout << "Masukkan 6 digit PIN untuk verifikasi masuk : "; cin >> passkey;
    cout << "Masukkan contoh nomor rekening              : "; cin >> norek;
    cout << "Masukkan Saldo untuk rekening               : "; cin >> saldo_awal;
    cout << "\n\n\n             PILIH BAHASA\n"
         << "             ------------\n"
         << "          LANGUAGE PREFERENCE\n\n"
         << "                       1. INDONESIA\n\n\n"
         << "                       2. ENGLISH\n\n\n"
         << "   INPUT ANGKA 3 UNTUK PEMBATALAN\n"
         << "-----------------------------------\n"
         << " TO VOID TRANSACTION PRESS NUMBER 3\n"; cin >> pref_lang;
    switch (pref_lang)
    {
    case 1:
        main_ops_id();
        break;
    
    case 2:
        main_ops_en();
        break;
    }
    return 0;
}
