# Modul 2 - Versi Paling Gampang untuk Persiapan Praktikum C++

File ini dibuat khusus dengan gaya penjelasan yang pelan, sederhana, dan nyambung ke file-file di folder `Second Lab Session`.

Target file ini:
- kamu paham istilah dasarnya
- kamu tidak bingung lagi dengan `Node`, `Node*`, anak kiri, anak kanan
- kamu bisa lihat hubungan antara teori dan kode praktikum

## 1. Gambaran Besar Materi Modul 2

Di modul ini, inti yang dipelajari adalah:
- `Tree`
- `Binary Search Tree (BST)`
- `Traversal BST`
- `Self-Balancing BST`
- `AVL Tree`
- `set`, `map`, dan kaitannya dengan `unordered_map`

Kalau disederhanakan:

- `Tree` = struktur data bercabang
- `BST` = tree yang isinya teratur
- `Traversal` = cara membaca isi tree
- `AVL` = BST yang otomatis dijaga supaya tidak miring
- `set/map` = versi STL yang sering dipakai kalau tidak ingin membuat tree manual

## 2. Cara Pikir Paling Dasar: Dari Array ke Tree

Sebelum masuk tree, bayangkan dulu:

- `array` seperti deretan kotak lurus
- `linked list` seperti rantai
- `tree` seperti cabang pohon

Contoh bentuk tree:

```text
        8
       / \
      3   10
     / \    \
    1   6    14
```

Jadi tree itu dipakai saat data lebih enak dibayangkan bercabang, bukan lurus.

## 3. Apa Itu Node?

`Node` adalah satu kotak data di dalam tree.

Kalau tree itu pohonnya, maka node adalah titik-titik cabangnya.

Contoh:

```text
        8
       / \
      3   10
```

Di gambar itu:
- `8` adalah satu node
- `3` adalah satu node
- `10` adalah satu node

Di kode, node biasanya ditulis seperti ini:

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
};
```

Artinya satu node punya:
- `key` = nilai data
- `left` = penunjuk ke anak kiri
- `right` = penunjuk ke anak kanan

## 4. Kenapa Ada `Node*`?

`Node*` artinya pointer ke `Node`.

Bahasa gampangnya:
- `Node` = kotaknya
- `Node*` = alamat menuju kotak itu

Kenapa perlu pointer?
- karena node harus bisa terhubung ke node lain
- anak kiri dan anak kanan bisa ada, bisa juga kosong
- jadi kita simpan alamat anaknya, bukan node penuh di dalam node

Contoh:

```cpp
Node* left;
Node* right;
```

Artinya:
- `left` menyimpan alamat anak kiri
- `right` menyimpan alamat anak kanan

Kalau tidak ada anak, nilainya:

```cpp
nullptr
```

Artinya:
- belum menunjuk ke node mana pun
- cabang itu kosong

## 5. Apa Itu Anak Kiri dan Anak Kanan?

Contoh:

```text
        8
       / \
      3   10
```

Di sini:
- `8` adalah parent
- `3` adalah anak kiri dari `8`
- `10` adalah anak kanan dari `8`

Kenapa disebut kiri dan kanan?
- karena tree biasa digambar bercabang ke kiri dan kanan

Dalam `binary tree`, satu node maksimal punya:
- 1 anak kiri
- 1 anak kanan

Jadi kemungkinan sebuah node:
- tidak punya anak
- punya 1 anak kiri saja
- punya 1 anak kanan saja
- punya 2 anak lengkap

Kalau lebih dari 2 anak?
- itu bukan `binary tree`
- itu `tree` biasa atau `general tree`

## 6. Istilah-Istilah Penting di Tree

### Root
Node paling atas.

Pada gambar:

```text
        8
       / \
      3   10
```

`8` adalah `root`.

### Parent
Node induk.

Contoh:
- `8` adalah parent dari `3` dan `10`

### Child
Node anak.

Contoh:
- `3` adalah child dari `8`
- `10` adalah child dari `8`

### Leaf
Node yang tidak punya anak.

Contoh:

```text
        8
       / \
      3   10
```

`3` dan `10` adalah leaf jika keduanya tidak punya anak lagi.

### Subtree
Bagian tree yang dimulai dari satu node tertentu.

Kalau kita ambil node `3`, lalu lihat semua cabangnya, itulah subtree dari `3`.

### Height
Tinggi tree atau tinggi node.

Catatan penting:
- ada soal yang menghitung tinggi berdasarkan `jumlah edge`
- ada soal yang menghitung tinggi berdasarkan `jumlah node`

Jadi selalu lihat definisi di soal.

Di `Menggali.cpp`, tinggi dihitung berdasarkan `edge`, karena:

```cpp
if (!p) {
    return -1;
}
```

Kalau node kosong = `-1`, maka leaf akan punya tinggi `0`.

## 7. Tree, Binary Tree, BST, dan AVL: Beda Singkatnya

### Tree
Struktur data bercabang. Tidak ada aturan harus 2 anak.

### Binary Tree
Tree yang setiap node maksimal punya 2 anak.

### BST
Binary tree dengan aturan:
- semua nilai di kiri < root
- semua nilai di kanan > root

### AVL
BST yang dijaga supaya tetap seimbang.

Versi hafalan cepat:
- `Tree` = bercabang
- `Binary Tree` = maksimal 2 anak
- `BST` = binary tree yang terurut
- `AVL` = BST yang seimbang

## 8. Struktur `Node` di `Menggali.cpp`

Di [Menggali.cpp](<C:/Users/asus/OneDrive/Desktop/Data Structure Practice/Second Lab Session/Menggali.cpp:4>) ada:

```cpp
struct Node {
    int key;
    Node *left;
    Node *right;

    explicit Node(int key) : key(key), left(nullptr), right(nullptr) {}
};
```

Artinya:
- `key` menyimpan angka di node
- `left` menunjuk ke anak kiri
- `right` menunjuk ke anak kanan
- constructor dipakai saat membuat node baru

Baris ini:

```cpp
explicit Node(int key) : key(key), left(nullptr), right(nullptr) {}
```

artinya:
- saat node dibuat, nilai `key` diisi
- anak kiri dibuat kosong dulu
- anak kanan dibuat kosong dulu

Jadi kalau kita menulis:

```cpp
new Node(8)
```

hasilnya seperti:
- `key = 8`
- `left = nullptr`
- `right = nullptr`

## 9. Bagaimana BST Bekerja?

Aturan BST:
- nilai kecil masuk ke kiri
- nilai besar masuk ke kanan

Misalnya input:

```text
8 3 10 1 6 14
```

Maka proses kasarnya:

### Masuk 8

```text
8
```

### Masuk 3

Karena `3 < 8`, masuk ke kiri:

```text
  8
 /
3
```

### Masuk 10

Karena `10 > 8`, masuk ke kanan:

```text
  8
 / \
3  10
```

### Masuk 1

Karena `1 < 8`, ke kiri.
Lalu `1 < 3`, ke kiri lagi.

```text
    8
   / \
  3   10
 /
1
```

### Masuk 6

Karena `6 < 8`, ke kiri.
Lalu `6 > 3`, ke kanan.

```text
    8
   / \
  3   10
 / \
1   6
```

### Masuk 14

Karena `14 > 8`, ke kanan.
Lalu `14 > 10`, ke kanan lagi.

```text
    8
   / \
  3   10
 / \    \
1   6    14
```

Itulah alasan BST enak untuk pencarian: kita tidak perlu cek semua node, cukup pilih kiri atau kanan.

## 10. Fungsi Insert di `Menggali.cpp`

Di [Menggali.cpp](<C:/Users/asus/OneDrive/Desktop/Data Structure Practice/Second Lab Session/Menggali.cpp:12>) ada:

```cpp
Node *insertBST(Node *root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->key) {
        root->left = insertBST(root->left, val);
    } else if (val > root->key) {
        root->right = insertBST(root->right, val);
    }

    return root;
}
```

Cara bacanya:

### Kalau `root` kosong
Berarti tempat itu belum ada node, jadi buat node baru.

### Kalau `val < root->key`
Masukkan ke subtree kiri.

### Kalau `val > root->key`
Masukkan ke subtree kanan.

### Lalu `return root`
Supaya sambungan tree tetap benar.

Intinya:
- fungsi ini membangun BST sedikit demi sedikit

## 11. Fungsi Search di `Menggali.cpp`

Di [Menggali.cpp](<C:/Users/asus/OneDrive/Desktop/Data Structure Practice/Second Lab Session/Menggali.cpp:26>) ada:

```cpp
Node *findNode(Node *root, int val) {
    while (root) {
        if (val == root->key) {
            return root;
        }

        if (val < root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return nullptr;
}
```

Cara pikirnya:
- kalau ketemu, pulangkan node itu
- kalau angka lebih kecil, pergi ke kiri
- kalau angka lebih besar, pergi ke kanan
- kalau akhirnya kosong, berarti tidak ketemu

Jadi pencarian BST tidak acak. Selalu ada alasan kenapa bergerak ke kiri atau kanan.

## 12. Fungsi Height di `Menggali.cpp`

Di [Menggali.cpp](<C:/Users/asus/OneDrive/Desktop/Data Structure Practice/Second Lab Session/Menggali.cpp:42>) ada:

```cpp
int heightInEdges(Node *p) {
    if (!p) {
        return -1;
    }

    return max(heightInEdges(p->left), heightInEdges(p->right)) + 1;
}
```

Artinya:
- kalau node kosong, tingginya `-1`
- kalau tidak kosong, tinggi node = tinggi terbesar anak kiri/kanan + 1

Contoh:

```text
    3
   / \
  1   6
```

- tinggi node `1` = `0`
- tinggi node `6` = `0`
- tinggi node `3` = `1`

Di soal `Menggali`, setelah ketemu node awal, yang dihitung adalah tinggi subtree dari node itu.

## 13. Apa Itu Traversal?

`Traversal` artinya cara mengunjungi semua node dalam urutan tertentu.

Tiga traversal paling penting:

### Inorder
Urutannya:
- kiri
- root
- kanan

Pada BST, hasil inorder akan terurut menaik.

Contoh:

```text
    8
   / \
  3   10
 / \
1   6
```

Hasil inorder:

```text
1 3 6 8 10
```

### Preorder
Urutannya:
- root
- kiri
- kanan

Biasanya dipakai saat ingin melihat root lebih dulu.

### Postorder
Urutannya:
- kiri
- kanan
- root

Biasanya dipakai saat anak harus diproses dulu baru parent.

Contoh kode:

```cpp
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
```

## 14. Kenapa BST Bisa Jelek?

Masalah BST biasa:
- kalau input datang berurutan, tree bisa menjadi miring

Contoh input:

```text
1 2 3 4 5
```

Hasilnya bisa seperti:

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
```

Ini jelek karena:
- bentuknya hampir seperti linked list
- pencarian jadi lebih lambat

## 15. Self-Balancing BST

Solusi dari BST yang mudah miring adalah `self-balancing BST`.

Intinya:
- tree akan dijaga supaya bentuknya tetap relatif seimbang
- tinggi tree tidak terlalu besar
- operasi search/insert/delete tetap cepat

Contoh self-balancing tree:
- `AVL Tree`
- `Red-Black Tree`

Di modul ini yang paling penting adalah `AVL Tree`.

## 16. Apa Itu AVL Tree?

`AVL Tree` adalah BST yang dijaga supaya tidak terlalu miring.

AVL tetap punya aturan BST:
- kiri lebih kecil
- kanan lebih besar

Tambahan aturan AVL:
- selisih tinggi kiri dan kanan tidak boleh terlalu jauh

Selisih itu disebut `balance factor`.

Rumus sederhananya:

```text
balance factor = tinggi kiri - tinggi kanan
```

Biasanya AVL mengizinkan:
- `-1`
- `0`
- `1`

Kalau lebih dari itu, tree dianggap tidak seimbang dan perlu rotasi.

## 17. Rotasi pada AVL

Rotasi adalah cara mengubah bentuk tree supaya seimbang lagi.

Jangan dibayangkan terlalu rumit dulu.
Bayangkan saja:
- tree lagi miring
- lalu susunannya digeser sedikit supaya lebih rapi

Jenis yang umum:
- `LL`
- `RR`
- `LR`
- `RL`

Yang paling penting untuk dipahami dulu:
- rotasi mengubah bentuk tree
- tapi aturan BST tetap dijaga
- hasil inorder tetap urut

## 18. Contoh AVL di `Second Lab Session`

### `Balance_Sheriff.cpp`

File ini cocok untuk belajar:
- AVL
- balance factor
- rotasi
- inorder traversal

Di sini ada:
- `height`
- `getBalance`
- `rotateLeft`
- `rotateRight`

Jadi ini file bagus untuk mulai memahami AVL.

### `Dayat_AVL.cpp`

File ini juga AVL, tapi sedikit lebih kaya karena:
- tree dibangun dengan insert AVL
- setelah itu tree dipakai lagi untuk perhitungan lain

Jadi dari sini kamu bisa lihat bahwa:
- AVL bukan cuma teori rotasi
- setelah tree jadi, tree bisa dipakai untuk menjawab query

## 19. Set dan Map di C++

Kadang soal tidak meminta kita bikin tree manual.

Kalau cuma butuh:
- simpan data
- cek ada atau tidak
- hitung frekuensi
- simpan pasangan key-value

sering lebih enak pakai STL seperti `set`, `map`, atau `unordered_map`.

### set

`set` dipakai untuk menyimpan data:
- unik
- otomatis terurut

Contoh:

```cpp
set<int> s;
s.insert(5);
s.insert(2);
s.insert(5);
```

Hasil isi set:

```text
2 5
```

Karena:
- `5` dobel tidak disimpan dua kali
- isi set terurut

### map

`map` menyimpan pasangan:

```text
key -> value
```

Contoh:

```cpp
map<string, int> nilai;
nilai["Andi"] = 90;
nilai["Budi"] = 85;
```

Artinya:
- key `"Andi"` punya value `90`
- key `"Budi"` punya value `85`

`map` terurut berdasarkan key.

### unordered_map

Mirip `map`, tapi:
- tidak terurut
- biasanya dipakai untuk pencarian cepat

Contoh:

```cpp
unordered_map<string, int> frek;
frek["apel"]++;
```

Ini sering dipakai untuk:
- frekuensi kata
- data berdasarkan nama
- lookup cepat

## 20. Kapan Pakai BST Manual, Set, Map, atau Unordered Map?

### Pakai BST manual kalau:
- soal memang minta struktur tree
- perlu anak kiri dan kanan
- perlu traversal
- perlu height
- perlu parent, rank, rotasi, dan hal-hal tree lain

### Pakai `set` kalau:
- hanya butuh data unik
- ingin otomatis terurut

### Pakai `map` kalau:
- butuh `key -> value`
- ingin key tetap terurut

### Pakai `unordered_map` kalau:
- butuh `key -> value`
- tidak peduli urutan
- ingin lookup cepat

## 21. Kaitan Materi dengan File di Second Lab Session

Bagian ini penting supaya kamu tahu teori mana muncul di soal mana.

### `Menggali.cpp`

Fokus:
- BST dasar
- insert
- search
- height subtree

Ini file paling bagus untuk mulai, karena konsepnya paling dasar dan bersih.

### `Dayat_Deadline.cpp`

Fokus:
- BST
- parent-child
- rank atau urutan data
- ukuran subtree (`size`)

Pelajaran penting:
- node bisa menyimpan data tambahan, bukan cuma `key`

### `Balance_Sheriff.cpp`

Fokus:
- AVL Tree
- balance factor
- rotasi
- inorder

Pelajaran penting:
- lihat perbedaan BST biasa dan AVL

### `Dayat_AVL.cpp`

Fokus:
- AVL Tree
- update height
- rotasi
- traversal rekursif untuk perhitungan lanjutan

Pelajaran penting:
- tree yang sudah dibangun bisa dipakai untuk menjawab query khusus

### `Kamus_Adit.cpp`

Fokus:
- frekuensi kata
- penggunaan `unordered_map`

Pelajaran penting:
- tidak semua soal modul ini perlu tree manual
- kadang associative container sudah cukup

### `Rahasia_Prajurit_Perang.cpp`

Fokus:
- penyimpanan data berdasarkan nama
- query cepat berdasarkan key
- penggunaan `unordered_map`

Pelajaran penting:
- kalau struktur yang dibutuhkan hanyalah `nama -> data`, `unordered_map` lebih praktis daripada bikin BST manual

## 22. Mini FAQ yang Sering Bikin Bingung

### Apakah node harus punya 2 anak?
Tidak.

Node bisa punya:
- 0 anak
- 1 anak kiri
- 1 anak kanan
- 2 anak

Yang penting, pada `binary tree`, maksimalnya 2.

### Kalau 3 anak bagaimana?
Berarti itu bukan `binary tree`.

### Kenapa anak kosong diisi `nullptr`?
Supaya program tahu bahwa cabang itu tidak menunjuk ke node mana pun.

### Kenapa pakai pointer?
Karena tree itu struktur dinamis. Node harus saling terhubung lewat alamat.

### Kenapa ada constructor `Node(int key)`?
Supaya saat node dibuat:
- nilai langsung terisi
- anak kiri dan kanan langsung aman bernilai `nullptr`

## 23. Urutan Belajar yang Paling Enak

Kalau mau belajar dari file yang ada di repo ini, urutan yang enak:

1. `Menggali.cpp`
2. `Dayat_Deadline.cpp`
3. `Balance_Sheriff.cpp`
4. `Dayat_AVL.cpp`
5. `Kamus_Adit.cpp`
6. `Rahasia_Prajurit_Perang.cpp`

Kenapa?
- mulai dari BST paling dasar
- lanjut ke BST dengan data tambahan
- lalu naik ke AVL
- terakhir lihat pemakaian container STL untuk lookup

## 24. Cara Membaca Soal Tree Saat Praktikum

Kalau nanti dapat soal tree, coba cek 5 hal ini:

### 1. Struktur apa yang dipakai?
- BST?
- AVL?
- `map`?
- `unordered_map`?

### 2. Apa yang disimpan di node?
- hanya `key`?
- ada `height`?
- ada `size`?

### 3. Operasi apa yang diminta?
- insert?
- search?
- traversal?
- height?
- rank?

### 4. Output akhirnya apa?
- angka?
- traversal?
- parent?
- hasil query?

### 5. Ada definisi khusus tidak?
- tinggi berdasarkan edge atau node?
- data unik atau bisa duplikat?

## 25. Checklist Hafalan Sebelum Praktikum

Kalau ini sudah paham, dasar kamu sudah kuat:

- `Node` adalah satu kotak data pada tree
- `Node*` adalah pointer ke node
- `left` dan `right` adalah anak kiri dan kanan
- `binary tree` maksimal 2 anak
- `BST` punya aturan kiri < root < kanan
- `search BST` berjalan ke kiri atau kanan sesuai perbandingan nilai
- `inorder` pada BST menghasilkan data terurut
- `height` harus dicek definisinya di soal
- `AVL` adalah BST yang dijaga seimbang
- `set` untuk data unik terurut
- `map` untuk `key -> value` terurut
- `unordered_map` untuk `key -> value` cepat tanpa urutan

## 26. Ringkasan Super Singkat

Kalau harus diringkas sekali lagi:

- `Tree` = struktur bercabang
- `Binary Tree` = maksimal 2 anak
- `BST` = binary tree yang terurut
- `Traversal` = cara mengunjungi node
- `AVL` = BST yang seimbang
- `set/map/unordered_map` = alat bantu STL untuk menyimpan dan mencari data tanpa harus selalu bikin tree manual

## 27. Penutup

Kalau kamu masih sering bingung, itu wajar. Materi tree memang terasa aneh di awal karena kita mulai berpikir bukan secara lurus, tapi bercabang.

Cara paling aman untuk memahami modul ini:
- pahami dulu arti node, pointer, anak kiri, anak kanan
- lalu pahami aturan BST
- lalu pahami traversal
- baru masuk AVL
- terakhir biasakan bedakan kapan pakai tree manual dan kapan cukup pakai STL

Kalau fondasi itu sudah enak, praktikum biasanya terasa jauh lebih ringan.
