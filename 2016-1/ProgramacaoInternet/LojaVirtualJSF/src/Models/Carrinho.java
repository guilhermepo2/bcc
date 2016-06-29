package Models;

import java.util.ArrayList;

public class Carrinho 
{
   ArrayList<Integer> produtos = new ArrayList<>();
   ArrayList<String> nomeProdutos = new ArrayList<>();
   float precoTotal;
   
   
   public ArrayList<String> getNomeProdutos()
   {
       return this.nomeProdutos;
   }
   public void setNomeProdutos(ArrayList<String> nomes)
   {
       this.nomeProdutos = nomes;
   }
   
   public ArrayList<Integer> getProdutos() {
       return produtos;
   }
   public void setProdutos(ArrayList<Integer> produtos)
   {
       this.produtos = produtos;
   }
   
   public Carrinho() 
   {
       precoTotal = 0;
   };
   
   public float getPreco()
   {
       return this.precoTotal;
   }
   
   public void adicionarItem(int id, float preco, String nome)
   {
       produtos.add(id);
       this.precoTotal += preco;
       nomeProdutos.add(nome);
   }
   
   public void removerItem(int id, float preco, String nome)
   {
       nomeProdutos.remove(nome);
       produtos.remove(new Integer(id));
       this.precoTotal -= preco;
   }
   
   public int getPosicao(int pos)
   {
       return produtos.get(pos);
   }
   
   public int getTamanho() {
       return produtos.size();
   }
   
   public void limparCarrinho()
   {
       nomeProdutos.clear();
       produtos.clear();
       precoTotal = 0;
   }
}
