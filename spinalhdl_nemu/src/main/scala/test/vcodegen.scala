package test
import spinal.core._

object test1{
    def test1_1()={
        def funct7Range = 31 downto 25
        def rdRange = 11 downto 7
        def funct3Range = 14 downto 12
        def rs1Range = 19 downto 15
        def rs2Range = 24 downto 20
        def rs3Range = 31 downto 27
        def csrRange = 31 downto 20
        println("(def funct7Range = 31 downto 25) is "+funct7Range)
    }
}


class test1_area extends Component {
  val timer = new Area {
    val counter = Reg(UInt(8 bit))
    val tick = counter === 0
    counter := counter - 1
    when(tick) {
      counter := 100
    }
  }
}

object vcodegen {
    def test2_adder( a:Int, b:Int ) : Int = {
      var sum:Int = 0
      sum = a + b
      return sum
   }
   
    def main(args: Array[String]): Unit = {
        val a=test2_adder(1,2)
        println("-------------------------test1_1 begin--------------------")
        test1.test1_1()
        println("-------------------------test1_1 end----------------------")
        
        
val verilog_path="/home/dy/ysyx-daiyao/spinalhdl_nemu/src/main/scala/test/testcode_gen" 
SpinalConfig(targetDirectory=verilog_path).generateVerilog(new test1_area)
    }
}
