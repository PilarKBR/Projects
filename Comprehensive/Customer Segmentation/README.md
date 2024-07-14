# Ringkasan Insight yang di Dapat
## Klaster yang terbentuk dari penerapan K-means pada RFM Scores untuk dataset ini berjumlah 5 klaster
## Profiling Cluster
- Bawah (Cluster 3): Rata-rata penggunanya merupakan Calon Pengguna yang Loyal dengan Total transaksi tergolong Rendah, namun Pengeluaran Paling Rendah dibanding golongan lain
- Menengah ke Bawah (Cluster 4): Rata-rata penggunanya merupakan Calon Pengguna yang Loyal dengan Total transaksi tergolong Paling Rendah, namun Pengeluaran tergolong Rendah
- Menengah (Cluster 0): Rata-rata penggunanya merupakan Calon Pengguna yang Loyal dengan Total transaksi dan Pengeluaran tergolong Sedang
- Menengah ke Atas (Cluster 2): Frekuensi belanja mereka memang terbilang rendah, namun sekalinya mereka bertransaksi, nominal yang dikeluarkan dan Total transaksi yang mereka lakukan tergolong Tinggi
- Atas (Cluster 1): Frekuensi belanja mereka memang terbilang rendah, namun sekalinya mereka bertransaksi, nominal yang dikeluarkan dan Total transaksi yang mereka lakukan merupakan yang paling tertinggi diantara golongan lain

# Tindakan yang Harus diambil untuk per Masing Klaster
- Bawah (Cluster 3):
Kebanyakan Prediksi Kategori Barang tiap Golongan Bawah (Cluster 3) pada notebook menunjukkan prediksi yang stabil, sehingga menawarkan promo dengan harga yang terjangkau untuk kategori barang lain merupakan tindakan yang tepat untuk Golongan Bawah.
- Menengah ke Bawah (Cluster 4):
Berikan promo (bisa berupa voucher diskon, cashback, dll) untuk kategori barang tertentu, yang disesuaikan dengan pembelian kategori barang yang pernah dibeli masing-masing pelanggan dalam 1 tahun terakhir.
- Menengah (Cluster 0):
Berikan rekomendasi barang yang dipersonalisasi berdasarkan riwayat transaksi mereka dan berikan promo-promo menarik pada kategori barang yang sering mereka beli.
- Menengah ke Atas (Cluster 2):
Jika kita telisik lagi, pergerakan grafik jumlah pengeluaran golongan menengah ke atas dalam satu bulan ini rata-rata stabil, namun range jumlah pengeluarannya akan selalu berbeda-beda tiap bulannya.
Hal ini diperkuat pada pergerakan grafik jumlah pengeluaran masing-masing kategori barang dan prediksinya dari golongan Menengah ke Atas ini sama seperti yang dijelaskan sebelumnya, sehingga pelanggan bergolongan Menengah ke Atas ini berpeluang besar merupakan pelanggan musiman.
Oleh karena itu, Tindakan yang tepat kepada pelanggan golongan menengah ke atas berupa pemberian rekomendasi dan promo-promo menarik pada kategori barang yang sedang musim/trend untuk 1 bulan ke depan
- Atas (Cluster 1):
Terapkan metode bundle untuk beberapa kategori barang dan/atau berikan pelayanan & benefit yang lebih dibanding Golongan lain
