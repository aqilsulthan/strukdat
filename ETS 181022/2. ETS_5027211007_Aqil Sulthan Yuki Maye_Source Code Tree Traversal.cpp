// Aqil Sulhan Yuki Maye
// 5027211007
// ETS Struktur Data (A)

#include <bits/stdc++.h>
using namespace std;

// deklarasi node
struct Node{
  string namaNode;
  Node *kiri, *kanan, *parent;
};

// deklarasi variabel pointer global
Node *root, *nodeBaru;

// buat tree baru
void buatTreeBaru(string namaNode)
{

  if( root != NULL )
    cout << "\nTree sudah dibuat" << endl;
  else{
    root = new Node();
    root->namaNode = namaNode;
    root->kiri = NULL;
    root->kanan = NULL;
    root->parent = NULL;
    cout << "\nNode " << namaNode << " berhasil dibuat menjadi root." << endl;
  }

}

// insert kiri
Node *insertkiri( string namaNode, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->kiri != NULL ){
      // jika ada
      cout << "\nNode "<< node->namaNode << " sudah ada anak kiri!" << endl;
      return NULL;
    }else{
      // jika tidak ada
      nodeBaru = new Node();
      nodeBaru->namaNode = namaNode;
      nodeBaru->kiri = NULL;
      nodeBaru->kanan = NULL;
      nodeBaru->parent = node;
      node->kiri = nodeBaru;
      cout << "\nNode " << namaNode << " berhasil ditambahkan ke anak kiri " << nodeBaru->parent->namaNode << endl;
      return nodeBaru;
    }

  }
}

// insert kanan
Node *insertkanan( string namaNode, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->kanan != NULL ){
      // jika ada
      cout << "\nNode " << node->namaNode << " sudah ada anak kanan!" << endl;
      return NULL;
    }else{
      // jika tidak ada
      nodeBaru = new Node();
      nodeBaru->namaNode = namaNode;
      nodeBaru->kiri = NULL;
      nodeBaru->kanan = NULL;
      nodeBaru->parent = node;
      node->kanan = nodeBaru;
      cout << "\nNode " << namaNode << " berhasil ditambahkan ke anak kanan " << nodeBaru->parent->namaNode << endl;
      return nodeBaru;
    }

  }
}

//  tree empty
bool empty()
{
  if( root == NULL )
    return true;
  else
  cout << " Tree tidak kosong, return nilai false / ";
    return false;
}

// renameNode
void renameNode(string namaNode, Node *node)
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ingin direname tidak ada!" << endl;
    else{
      string temp = node->namaNode;
      node->namaNode = namaNode;
      cout << "\nNama node " << temp << " berhasil direname menjadi " << namaNode << endl;
    }
  }
}

// ambilNode
void ambilNode( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ingin direname tidak ada!" << endl;
    else{
      cout << "\nNode yang ingin direname : " << node->namaNode << endl;
    }
  }
}

// cariNode
void cariNode( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang dicari tidak ada!" << endl;
    else{
      cout << "\nCari node : " << node->namaNode << endl;
      cout << endl;
      cout << "Penjelasan node "<< node->namaNode << " :" << endl;
      cout << "Root Node : " << root->namaNode << endl;
      
      if( !node->parent )
        cout << "Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "Parent Node : " << node->parent->namaNode << endl;

      if( node->parent != NULL && node->parent->kiri != node && node->parent->kanan == node )

      cout << "Saudara : " << node->parent->kiri->namaNode << endl;

      else if( node->parent != NULL && node->parent->kanan != node && 
      node->parent->kiri == node )
      
        cout << "Saudara : " << node->parent->kanan->namaNode << endl;
      else
        cout << "Saudara : (tidak punya saudara)" << endl;

      if( !node->kiri )
        cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "Anak Kiri Node : " << node->kiri->namaNode << endl;

      if( !node->kanan )
        cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "Anak Kanan Node : " << node->kanan->namaNode << endl;

    }    

  }
}

// Tree traversal
// preOrder
void preOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!" << endl;
  else{

    if( node != NULL ){
      cout << node->namaNode << ", ";
      preOrder(node->kiri);
      preOrder(node->kanan);
    }

  }

}

// inOrder
void inOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!" << endl;
  else{

    if( node != NULL ){
      inOrder(node->kiri);
      cout << node->namaNode << ", ";
      inOrder(node->kanan);
    }

  }

}

// postOrder
void postOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!" << endl;
  else{

    if( node != NULL ){
      postOrder(node->kiri);
      postOrder(node->kanan);
      cout << node->namaNode << ", ";
    }

  }

}

// ukuranTree
int ukuranTree(Node *node = root){
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!" << endl;
    return 0;
  }else{

    if( !node ){
      return 0;
    }else{
      return 1 + ukuranTree( node->kiri ) + ukuranTree(node->kanan);
    }

  }
}

// tinggiTree
int tinggiTree( Node *node = root )
{
  if( !root ){
      cout << "\nBuat tree terlebih dahulu!" << endl;
      return 0;
    }else{
      if( !node ){
        return 0;
      }else{
        int tinggiTreeKiri = tinggiTree( node->kiri );
        int tinggiTreeKanan = tinggiTree( node->kanan );

        if( tinggiTreeKiri >= tinggiTreeKanan ){
          return tinggiTreeKiri + 1;
        }else{
          return tinggiTreeKanan + 1;
        }

      }
    }
}

// statistikTree
void statistikTree()
{
  cout << "\nUkuran Tree : " << ukuranTree() << endl;
  cout << "Level/Tinggi Tree : " << tinggiTree() << endl;
  cout << "Rata-rata node dari tree : " << ukuranTree() / tinggiTree() << endl;
}


int main()
{
  cout << "=============FAMILY TREE TRAVERSAL==================";
  buatTreeBaru("Susanto");

  Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ, *nodeK, *nodeL;

  nodeB = insertkiri("Joni", root);
  nodeC = insertkanan("Kartika", root);
  nodeD = insertkiri("Fikri", nodeB);
  nodeE = insertkanan("Bahrudin", nodeB);
  nodeF = insertkiri("Fayza", nodeC);
  nodeG = insertkanan("Ibadul", nodeC);
  nodeH = insertkiri("Emil", nodeE);
  nodeI = insertkanan("Baihaki", nodeE);
  nodeJ = insertkiri("Thifatul", nodeH);
  nodeK = insertkanan("Syifa", nodeH);
  nodeL = insertkiri("Melvin", nodeJ);
  
  cout << endl;
  cout << "==============================================";
  cout << "\n"<<endl;
  cout << "Apakah tree kosong?";
  cout << empty() << endl << endl;

  cout << "=============PREORDER=========================";
  cout << "\nPreOrder :" << endl;
  preOrder(root);
  cout << "\n";
  ambilNode(nodeC);
  renameNode("Indah", nodeC);
  cariNode(nodeC);
  cout << "\nPreOrder setelah direname :" << endl;
  preOrder(root);
  cout << "\n";

  cout << "\n=============INORDER=========================";
  cout << "\nInOrder :" << endl;
  inOrder(root);
  cout << "\n";
  ambilNode(nodeD);
  renameNode("Aisyah", nodeD);
  cariNode(nodeD);
  cout << "\nInOrder setelah direname :" << endl;
  inOrder(root);
  cout << "\n";
  
  cout << "\n=============POSTORDER=========================";
  cout << "\nPostOrder :" << endl;
  postOrder(root);
  cout << "\n";
  ambilNode(nodeJ);
  renameNode("Imran", nodeJ);
  cariNode(nodeJ);
  cout << "\nPostOrder setelah direname :" << endl;
  postOrder(root);
  cout << "\n" << endl;  
  
  cout << "=================STATISTIK TREE==================";
  statistikTree();
}
