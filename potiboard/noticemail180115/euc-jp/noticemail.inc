<?php
/*
** �᡼�����Υ��饹(EUC-JP) lot.180115
**
** http://www.punyu.net/php/
** by SakaQ
** https://sakots.red/poti/
** by sakots
**
** 2018/01/15 php7�б���¤
** 2007/03/01 ��̾(Subject)�����ܸ줬�ޤޤ�����MIME�إå��Ѵ�����褦���ѹ�
** 2005/01/14 jcode.php(v1.35��) �б�
** 2004/01/19 ����

���Υ�����ץȤϡ�PHP�ηǼ������˥᡼�����ε�ǽ���ɲä��륯�饹�Ǥ���
�����Τ���Ū�ˤ��Ƥ���Τ�ź�եե�������б����Ƥ��ޤ���

�ڻ�����ˡ��
 ���Υ��饹��Ȥ�����������ץȤ���Ƭ�� noticemail.inc �� require() �� include() ���Ʋ�������
 ����ǻȤ���褦�ˤʤ�ޤ���
 ����: include("noticemail.inc");
 ���Ȥϡ������Ϥ��ǡ����򥻥åȤ��ơ�noticemail::send() ���������ޤ���

�ڴؿ�������
    noticemail::send(�᡼��ǡ���[, MB�ؿ����ѥե饰])
���᡼��ǡ����ϡ�����˳Ƽ����������ƥ��åȤ��ޤ���
��MB�ؿ����ѥե饰�ϡ�MB�ؿ�����Ѥ������ʤ�����'0'�򥻥åȤ��ޤ��������������ξ���jcode.phps(��v1.34)�ޤ���jcode.php(v1.35��)��ɬ�פˤʤ�ޤ���
  MB�ؿ���Ȥ����Ͼ�ά���Ʋ�������
�������Ѵ����Ǥ��ʤ����������Ǥ��ޤ���(false���֤��ޤ�)

������ǡ������ܡۢ���Ȥ��� $data ���������ޤ�
  ��$data[to]
 - ������Υ᡼�륢�ɥ쥹��

  ��$data[subject]
 - ���Υ᡼�����̾��

  ��$data[name]
 - ��ƼԤ�̾����

  ��$data[email]
 - ��ƼԤΥ᡼�륢�ɥ쥹��
   �̾From�˻Ȥ��ޤ������ܸ졢'sage'��'http://:'�Τɤ줫���ޤޤ�Ƥ��뤫̤����ξ��
   ���ؤ�꤬From�˥��åȤ���ޤ���

 �������ޤǤ�ɬ�ܤǤ����ʲ���ɬ�פ˱����ƥ��åȤ��Ʋ�������

  ��$data[option]
 - �ɲ���ƥǡ�����ʣ�����åȤǤ��ޤ���
   ���åȤ���Ȥ��ϡ�[option][]="��̾,����" �Ȥ��Ʋ�������

  ��$data[comment]
 - ��ƥǡ�������ʸ��
   ��ʸ�ϡ�<br>�ޤ���<br />�� \n ���ᤷ�Ƥ��饻�åȤ��Ʋ�������
 ����: $data[comment] = preg_replace("/<br(( *)|( *)/)>/i","\n", $comment);

�ڻ�����ۢ��ºݤˤ��ѿ���Ȥ�����Ƚ��פ�����٤�ľ�����Ƥ򥻥åȤ��Ƥ��ޤ�

$data[to] = 'me@hoge.net';
$data[subject] = '�ʤ���Ƥ���Ƥޤ��衼';
$data[name] = '̵̾������';
$data[email] = 'hoge@hoge.com';
$data[option][] = 'URL,http://hogehoge.com/';
$data[option][] = '����������,http://hoge.net/poti/src/OB11111111.png';
$data[comment] = '�������������ˤ�';
noticemail::send($data);

�ڤ����ա�
��sendmail �ʤɤ� MTA �����󥹥ȡ��롦���ꤵ��Ƥ��ʤ��ȻȤ��ޤ���
���ǡ��������å��Ϥ��Ƥ��ޤ��������顼��å������ϽФ��Ƥޤ���
�������졢���Υ�����ץȤˤ�겿�餫��»����ȯ�����Ƥ⡢������Ǥ�����餤�ޤ���
  ���ʤ���Ǥ�����Ѥ��Ʋ�������
��������������ޤ��󤬡���¤�������ۤϼ�ͳ�ˤɤ�����
��������ϡ�<http://www.punyu.net/bbs/ibbs/ibbs.php>�ޤǤɤ�����
*/

class noticemail{

	function send($data,$usemb="1"){
		$name = $data[name];
		$from = $data[email];
		$line = "---------------------------------------------------------------------\n";

		// �إå������
		$MailHeaders  = "Mime-Version: 1.0\n";
		$MailHeaders .= "Content-Type: text/plain; charset=ISO-2022-JP\n";
		$MailHeaders .= "Content-Transfer-Encoding: 7bit\n";
		$MailHeaders .= "X-Mailer: NoticeMail/PHP".phpversion()."\n";

		// �᡼����ʸ����
		$Message = "��".$data[subject]."\n";
		$Message .= "Date: ".gmdate("Y/m/d H:i:s",time()+9*3600)."\n";
		$Message .= "Host: ".@gethostbyaddr(getenv("REMOTE_ADDR"))."\n";
		$Message .= "UserAgent: ".getenv("HTTP_USER_AGENT")."\n";
		$Message .= $line;
		$Message .= "Name: ".$name."\n";
		$Message .= "e-Mail: ".$data[email]."\n";
		$option = $data[option];
		if(is_array($option)){
			for($i = 0; $i < count($option); $i++){
				list($optitle,$opvalue) = explode(",", rtrim($option[$i]));
				$Message .= $optitle.": ".$opvalue."\n";
			}
		}
		$Message .= $line;
		if($data[comment]){
			$com = str_replace("\r\n", "\n", $data[comment]);	// ����ʸ��������
			$com = str_replace("\r", "\n", $com);
			$com = preg_replace("/^(\n)+|(\n)+$/", "", $com);	// Ϣ³���Ԥ�ä�
			$Message .= $com;
		}
		if(get_magic_quotes_gpc()){	// \�ϼ��
			$Message = stripslashes($Message);
			$name = stripslashes($name);
			$from = stripslashes($from);
		}

		$Message = str_replace("\n", "\r\n", $Message);	// ����ʸ��������

		// �����Ѵ�������
		if(function_exists("mb_internal_encoding")&&function_exists("mb_convert_encoding")&&function_exists("mb_convert_kana")
		   &&$usemb){

			mb_internal_encoding("EUC-JP");
			// Ⱦ���б�
			$Message = mb_convert_kana($Message);
			$name = mb_convert_kana($name);
			$from = mb_convert_kana($from);
			// ���餫�˥᡼�륢�ɥ쥹����ʤ�ʪ�Ͻ���
			if(preg_match("/[\x80-\xA0]/",$from)||stristr($from,'sage')||stristr($from,'http://'))	$from = '';
			// �᡼�륢�ɥ쥹���ʤ�������ؤ�
			if(!$from)	$from = 'nomail@'.getenv("HTTP_HOST");
			// ���ܸ�ʤ�MIME�إå�
			if(preg_match("/[\x80-\xA0]/",$name)){
				$name = "=?iso-2022-jp?B?".base64_encode(mb_convert_encoding($name,"JIS","auto"))."?=";
			}
			// �إå���From�ɲ�
			$MailHeaders .= "From: ".$name." <".$from.">\n";

			$MailHeaders = str_replace("\n", "\r\n", $MailHeaders);	// ����ʸ��������

			// Subject�����ܸ줬�����MIME�إå�
			if(preg_match("/[\x80-\xA0]/",$data[subject])){
				$data[subject] = "=?iso-2022-jp?B?".base64_encode(mb_convert_encoding($data[subject],"JIS","auto"))."?=";
			}
			// �᡼������
			mail($data[to],
				$data[subject],
				mb_convert_encoding($Message,"JIS","auto"), $MailHeaders);

		}elseif(@file_exists("jcode.phps")||@file_exists("jcode.php")){

			if(@file_exists("jcode.phps")){ require_once('jcode.phps'); }
			else{ require_once('jcode.php'); }
			// Ⱦ���б�
			$Message = HANtoZEN($Message,1);
			$name = HANtoZEN($name,1);
			$from = HANtoZEN($from,1);
			// ���餫�˥᡼�륢�ɥ쥹����ʤ�ʪ�Ͻ���
			if(preg_match("/[\x80-\xA0]/",$from)||stristr($from,'sage')||stristr($from,'http://'))	$from = '';
			// �᡼�륢�ɥ쥹���ʤ�������ؤ�
			if(!$from)	$from = 'nomail@'.getenv("HTTP_HOST");
			// ���ܸ�ʤ�MIME�إå�
			if(preg_match("/[\x80-\xA0]/",$name)){
				$name = "=?iso-2022-jp?B?".base64_encode(JcodeConvert($name,0,3))."?=";
			}
			// �إå���From�ɲ�
			$MailHeaders .= "From: ".$name." <".$from.">\n";

			$MailHeaders = str_replace("\n", "\r\n", $MailHeaders);	// ����ʸ��������

			// Subject�����ܸ줬�����MIME�إå�
			if(preg_match("/[\x80-\xA0]/",$data[subject])){
				$data[subject] = "=?iso-2022-jp?B?".base64_encode(JcodeConvert($data[subject],0,3))."?=";
			}
			// �᡼������
			mail($data[to],
				$data[subject],
				JcodeConvert($Message,0,3), $MailHeaders);

		}else{ return false; }
		return true;
	}
}
?>