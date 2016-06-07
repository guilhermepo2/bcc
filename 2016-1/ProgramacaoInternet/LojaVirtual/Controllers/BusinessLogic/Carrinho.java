package BusinessLogic;

import java.util.ArrayList;

public class Carrinho 
{
   ArrayList<Integer> produtos = new ArrayList<>();
   
   public Carrinho() 
   {
       super();
   };
   
   public void adicionarItem(int id)
   {
       produtos.add(id);
   }
   
   public void removerItem(int id)
   {
       produtos.remove(new Integer(id));
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
       produtos.clear();
   }
}
