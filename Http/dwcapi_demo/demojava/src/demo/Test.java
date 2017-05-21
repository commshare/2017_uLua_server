package demo;

import java.util.UUID;

public class Test 
{
	public static void main(String[] args) 
	{
		// �ٶ������GM��̨�˺�
		String gmAcc = "ybiaoCNY123z";
		// �ٶ������GM��̨�˺�����
		String gmPwd = "123456";
		// �ٶ������GM��̨������Կ
		String devKey = "fa4c1529f25e426ea489a88637178d36";

        OpMgr mgr = new OpMgr(gmAcc, gmPwd, devKey);
  
        String retStr = "";
        
        String playerAcc = "123zyb003";
       
        retStr = mgr.createPlayer(playerAcc, "abc123");
        System.out.println("������ҽ��----------------------------");
        System.out.println(retStr);
        
        retStr = mgr.playerSaveMoney(playerAcc, 500, UUID.randomUUID().toString().replace("-", ""), "");
        System.out.println("��Ҵ����----------------------------");
        System.out.println(retStr);
        
        retStr = mgr.playerDrawMoney(playerAcc, 500, UUID.randomUUID().toString().replace("-", ""), "");
        System.out.println("��������----------------------------");
        System.out.println(retStr);

        retStr = mgr.queryPlayerTradingRecord(playerAcc, 0, 0, 0, "2016-03-01 00:00:00", "2016-03-31 23:59:59");
        System.out.println("��Ҵ�ȡ���¼1----------------------------");
        System.out.println(retStr);

        retStr = mgr.queryPlayerTradingRecord(playerAcc, 2, 1, 9, "2016-03-01 00:00:00", "2016-03-31 23:59:59");
        System.out.println("��Ҵ�ȡ���¼2----------------------------");
        System.out.println(retStr);

        retStr = mgr.queryPlayerInfo(playerAcc);
        System.out.println("��ѯ�����Ϣ���----------------------------");
        System.out.println(retStr);

        retStr = mgr.queryPlayerOnline(playerAcc);
        System.out.println("��ѯ����Ƿ�����----------------------------");
        System.out.println(retStr);

        retStr = mgr.logoutPlayer(playerAcc, 600);
        System.out.println("�ǳ����----------------------------");
        System.out.println(retStr);

        retStr = mgr.clearLoginFailed(playerAcc);
        System.out.println("������ҵ�¼ʧ�ܴ������---------------------------");
        System.out.println(retStr);

        retStr = mgr.unlockPlayer(playerAcc);
        System.out.println("������ҽ��---------------------------");
        System.out.println(retStr);
        
        queryMoneyChange(mgr, playerAcc);
        queryWinLose(mgr, playerAcc);
        
        updatePwd(mgr, playerAcc);
        
        queryWinLoseSum(mgr);
        
        playerOp(mgr, playerAcc);
	}

	static void queryMoneyChange(OpMgr mgr, String playerAcc)
    {
		String retStr = mgr.queryPlayerMoneyChange(playerAcc, 0, 0, "2016-04-01 00:00:00", "2016-04-27 23:59:59");
		System.out.println("��һ��ұ仯���1----------------------------");
		System.out.println(retStr);

        retStr = mgr.queryPlayerMoneyChange(playerAcc, 1, 100, "2016-04-01 00:00:00", "2016-04-27 23:59:59");
        System.out.println("��һ��ұ仯���2----------------------------");
        System.out.println(retStr);
    }

    static void queryWinLose(OpMgr mgr, String playerAcc)
    {
    	String retStr = mgr.queryPlayerWinLose(playerAcc, 0, 0, "2016-04-01", "2016-04-27");
    	System.out.println("�����Ӯ���1----------------------------");
    	System.out.println(retStr);

        retStr = mgr.queryPlayerWinLose(playerAcc, 1, 100, "2016-04-01", "2016-04-27");
        System.out.println("�����Ӯ���2----------------------------");
        System.out.println(retStr);
    }
    
    static void updatePwd(OpMgr mgr, String playerAcc)
    {
    	String retStr = mgr.updatePlayerPwd(playerAcc, "123456", "654321");
    	System.out.println("�޸�������1----------------------------");
    	System.out.println(retStr);

        retStr = mgr.updatePlayerPwd(playerAcc, "654321", "123456");
        System.out.println("�޸�������2----------------------------");
        System.out.println(retStr);
    }
    
    static void queryWinLoseSum(OpMgr mgr)
    {
    	String retStr = mgr.queryWinLoseSum("2016-05-01", "2016-05-08");
    	System.out.println("��Ӯ�ܺ�1----------------------------");
    	System.out.println(retStr);

        retStr = mgr.queryWinLoseSum("2016-05-08", "2016-06-08");
        System.out.println("��Ӯ�ܺ�2----------------------------");
        System.out.println(retStr);
    }
    
    static void playerOp(OpMgr mgr, String playerAcc)
    {
    	String retStr = mgr.playerOp(playerAcc, 0);
    	System.out.println("ͣ����----------------------------");
    	System.out.println(retStr);

        retStr = mgr.playerOp(playerAcc, 1);
        System.out.println("�����----------------------------");
        System.out.println(retStr);
    }
}
