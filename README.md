# ESP8266-SmartDoorLock-Firebase
**Judul: ESP8266-SmartDoorLock-Firebase**
# ESP8266 Smart Door Lock with Firebase

![WhatsApp Image 2023-12-11 at 12 51 20_8aec5fe8](https://github.com/11neuty/ESP8266-SmartDoorLock-Firebase/assets/49444532/c989f8ba-6e15-452a-a33c-cb03320624ec)
![WhatsApp Image 2023-12-11 at 12 51 19_47ab3a90](https://github.com/11neuty/ESP8266-SmartDoorLock-Firebase/assets/49444532/981dd7ec-f423-4630-9b08-246ae8cac517)





## Deskripsi
Proyek ini adalah implementasi sistem pintu pintar menggunakan mikrokontroler ESP8266, Firebase sebagai database dan server, serta MIT Inventor untuk aplikasi seluler. Sistem ini memungkinkan pengguna untuk membuka atau menutup pintu menggunakan aplikasi seluler yang terhubung dengan perangkat pintar.


## Fitur
1. **RFID Authentication:** Sistem dapat membaca RFID card dan memberikan keterangan apakah kartu yang dibaca benar atau salah.
2. **Remote Door Control:** Pengguna dapat membuka atau menutup pintu dari jarak jauh menggunakan aplikasi seluler.
3. **Firebase Integration:** Data akses dan log aktivitas disimpan dan diakses melalui Firebase, memungkinkan pengelolaan dan pemantauan yang efisien.
4. **Real-time Status Updates:** Aplikasi seluler memberikan pembaruan status pintu secara real-time, termasuk informasi apakah pintu sedang terbuka atau tertutup.
5. **Secure Communication:** Komunikasi antara ESP8266 dan Firebase dilakukan melalui protokol aman, memastikan keamanan data.

## Komponen Utama
1. **ESP8266:** Mengontrol perangkat pintu dan menangani komunikasi dengan Firebase.
2. **RFID Module:** Digunakan untuk membaca dan memverifikasi RFID card.
3. **Firebase Realtime Database:** Menyimpan data akses dan log aktivitas pintu.
4. **MIT Inventor:** Membuat antarmuka pengguna seluler untuk mengontrol pintu pintar.

## Petunjuk Penggunaan
1. **Hardware Setup:** Sambungkan ESP8266 dengan modul RFID dan pastikan perangkat keras terhubung dengan baik.
2. **Firebase Configuration:** Atur konfigurasi Firebase, termasuk API key dan URL database.
3. **MIT Inventor App:** Unduh dan instal aplikasi MIT Inventor pada perangkat seluler Anda.
4. **Connectivity:** Hubungkan aplikasi seluler dengan perangkat pintar menggunakan token otentikasi Firebase.
5. **Enjoy:** Gunakan aplikasi untuk membuka atau menutup pintu, dan lihat log aktivitas pada Firebase.

## Kontribusi
Kami mengundang kontribusi dari komunitas. Silakan berkontribusi dengan memberikan saran, melaporkan bug, atau mengirim pull request untuk peningkatan fitur.

## Lisensi
Proyek ini dilisensikan di bawah [MIT License](LICENSE).

## Pengembang
- [Ryan D. Pratama](https://github.com/11neuty)
- [Arkan Anis Shafry](https://github.com/Arkan03)

