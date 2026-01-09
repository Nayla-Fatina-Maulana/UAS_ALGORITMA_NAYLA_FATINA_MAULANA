#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pegawai {
    string nama;
    int jam;
    int honor = 25000;
    int lembur;
    int total;
};

class Kalkulator {
public:
    void hitung(Pegawai &p) {
        p.lembur = (p.jam > 8) ? (p.jam - 8) * 1500 : 0;
        p.total  = p.honor + p.lembur;
    }
};

int main() {
    cout << "NAMA : NAYLA FATINA MAULANA\nNIM  : 251011700769\n";

    vector<Pegawai> data;
    Kalkulator k;
    int pilih;

    while (true) {
        cout << "\n1. Input Data\n2. Tampilkan Tabel\n3. Keluar\nPilih: ";
        cin >> pilih;
        cin.ignore(); // buang newline

        if (pilih == 3) break;

        if (pilih == 1) {
            int n;
            cout << "Jumlah Pegawai: ";
            cin >> n;
            cin.ignore();

            data.clear();

            for (int i = 0; i < n; i++) {
                Pegawai p;
                cout << "\nPegawai ke-" << i+1 << endl;
                cout << "Nama      : ";
                getline(cin, p.nama);
                cout << "Jam Kerja : ";
                cin >> p.jam;
                cin.ignore();

                k.hitung(p);
                data.push_back(p);
            }
        }

        else if (pilih == 2 && !data.empty()) {
            cout << "\nPT. UNPAM VIKTOR\n";
            cout << "Nama\t\tHonor\tJam\tLembur\tTotal\n";

            int totalSemua = 0;
            for (auto &p : data) {
                cout << p.nama << "\t" 
                     << p.honor << "\t"
                     << p.jam   << "\t"
                     << p.lembur<< "\t"
                     << p.total << endl;
                totalSemua += p.total;
            }
            cout << "\nTotal Honor Semua Pegawai: Rp " << totalSemua << endl;
        }
    }

    return 0;
}
