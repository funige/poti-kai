<?php
/*
** ���[���ʒm�N���X(Shift_JIS) lot.180115
**
** http://www.punyu.net/php/
** by SakaQ
** https://sakots.red/poti/
** by sakots
**
** 2018/01/15 php7�Ή�����
** 2007/03/01 ����(Subject)����{�ꂪ�܂܂��ꍇ��MIME�w�b�_�ϊ�����悤�ɕύX
** 2005/01/14 jcode.php(v1.35�`) �Ή�
** 2004/01/19 ���J

���̃X�N���v�g�́APHP�̌f�����Ƀ��[���ʒm�@�\��ǉ�����N���X�ł��B
���ʒm��ړI�ɂ��Ă���̂œY�t�t�@�C���ɑΉ����Ă��܂���B

�y�g�p���@�z
 ���̃N���X���g�������X�N���v�g�̐擪�� noticemail.inc �� require() �� include() ���ĉ������B
 ����Ŏg����悤�ɂȂ�܂��B
 ����: include("noticemail.inc");
 ���Ƃ́A�󂯓n���f�[�^���Z�b�g���āAnoticemail::send() �ő��M���܂��B

�y�֐������z
    noticemail::send(���[���f�[�^[, MB�֐��g�p�t���O])
�E���[���f�[�^�́A�z��Ɋe��ݒ�����ăZ�b�g���܂��B
�EMB�֐��g�p�t���O�́AMB�֐����g�p�������Ȃ��ꍇ��'0'���Z�b�g���܂��B�������A���̏ꍇ��jcode.phps(�`v1.34)�܂���jcode.php(v1.35�`)���K�v�ɂȂ�܂��B
  MB�֐����g���ꍇ�͏ȗ����ĉ������B
�E�����ϊ����ł��Ȃ��ꍇ�͑��M�ł��܂���(false��Ԃ��܂�)

�y�ݒ�f�[�^���ځz����Ƃ��� $data �Ő������܂�
  �E$data[to]
 - �ʒm��̃��[���A�h���X�B

  �E$data[subject]
 - �ʒm���[���̑薼�B

  �E$data[name]
 - ���e�҂̖��O�B

  �E$data[email]
 - ���e�҂̃��[���A�h���X�B
   �ʏ�AFrom�Ɏg���܂������{��A'sage'�A'http://:'�̂ǂꂩ���܂܂�Ă��邩���ݒ�̏ꍇ
   ��ւ�肪From�ɃZ�b�g����܂��B

 �������܂ł��K�{�ł��B�ȉ��͕K�v�ɉ����ăZ�b�g���ĉ������B

  �E$data[option]
 - �ǉ����e�f�[�^�B�����Z�b�g�ł��܂��B
   �Z�b�g����Ƃ��́A[option][]="�薼,���e" �Ƃ��ĉ������B

  �E$data[comment]
 - ���e�f�[�^�̖{���B
   �{���́A<br>�܂���<br />�� \n �ɖ߂��Ă���Z�b�g���ĉ������B
 ����: $data[comment] = preg_replace("/<br(( *)|( *)/)>/i","\n", $comment);

�y�g�p��z�����ۂɂ͕ϐ����g�����A����Ղ�����ׂɒ��ړ��e���Z�b�g���Ă��܂�

$data[to] = 'me@hoge.net';
$data[subject] = '�Ȃ񂩓��e����Ă܂���[';
$data[name] = '����������';
$data[email] = 'hoge@hoge.com';
$data[option][] = 'URL,http://hogehoge.com/';
$data[option][] = '���G�����G,http://hoge.net/poti/src/OB11111111.png';
$data[comment] = '���G���������ɂ�';
noticemail::send($data);

�y�����Ӂz
�Esendmail �Ȃǂ� MTA ���C���X�g�[���E�ݒ肳��Ă��Ȃ��Ǝg���܂���B
�E�f�[�^�`�F�b�N�͂��Ă��܂����A�G���[���b�Z�[�W�͏o���Ă܂���B
�E������A���̃X�N���v�g�ɂ�艽�炩�̑��Q���������Ă��A���̐ӔC�����͕����܂���B
  ���Ȃ̐ӔC�ŗ��p���ĉ������B
�E���쌠�͕������܂��񂪁A�����E�Ĕz�z�͎��R�ɂǂ����B
�E������́A<http://www.punyu.net/bbs/ibbs/ibbs.php>�܂łǂ����B
*/

class noticemail{

	function send($data,$usemb="1"){
		$name = $data[name];
		$from = $data[email];
		$line = "---------------------------------------------------------------------\n";

		// �w�b�_���w��
		$MailHeaders  = "Mime-Version: 1.0\n";
		$MailHeaders .= "Content-Type: text/plain; charset=ISO-2022-JP\n";
		$MailHeaders .= "Content-Transfer-Encoding: 7bit\n";
		$MailHeaders .= "X-Mailer: NoticeMail/PHP".phpversion()."\n";

		// ���[���{���쐬
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
			$com = str_replace("\r\n", "\n", $data[comment]);	// ���s�����̓���
			$com = str_replace("\r", "\n", $com);
			$com = preg_replace("/^(\n)+|(\n)+$/", "", $com);	// �A�����s������
			$Message .= $com;
		}
		if(get_magic_quotes_gpc()){	// \�͎��
			$Message = stripslashes($Message);
			$name = stripslashes($name);
			$from = stripslashes($from);
		}

		// �����ϊ������M
		if(function_exists("mb_internal_encoding")&&function_exists("mb_convert_encoding")&&function_exists("mb_convert_kana")
		   &&$usemb){

			mb_internal_encoding("SJIS");
			// ���p�Ή�
			$Message = mb_convert_kana($Message);
			$name = mb_convert_kana($name);
			$from = mb_convert_kana($from);
			// ���炩�Ƀ��[���A�h���X����Ȃ����͏��O
			if(preg_match("/[\x80-\xA0]/",$from)||stristr($from,'sage')||stristr($from,'http://'))	$from = '';
			// ���[���A�h���X���Ȃ���Α�ւ�
			if(!$from)	$from = 'nomail@'.getenv("HTTP_HOST");
			// ���{��Ȃ�MIME�w�b�h
			if(preg_match("/[\x80-\xA0]/",$name)){
				$name = "=?iso-2022-jp?B?".base64_encode(mb_convert_encoding($name,"JIS","auto"))."?=";
			}
			// �w�b�_��From�ǉ�
			$MailHeaders .= "From: ".$name." <".$from.">\n";
			// Subject�ɓ��{�ꂪ�����MIME�w�b�h
			if(preg_match("/[\x80-\xA0]/",$data[subject])){
				$data[subject] = "=?iso-2022-jp?B?".base64_encode(mb_convert_encoding($data[subject],"JIS","auto"))."?=";
			}
			// ���[�����M
			mail($data[to],
				$data[subject],
				mb_convert_encoding($Message,"JIS","auto"), $MailHeaders);

		}elseif(@file_exists("jcode.phps")||@file_exists("jcode.php")){

			if(@file_exists("jcode.phps")){ require_once('jcode.phps'); }
			else{ require_once('jcode.php'); }
			// ���p�Ή�
			$Message = HANtoZEN($Message,2);
			$name = HANtoZEN($name,2);
			$from = HANtoZEN($from,2);
			// ���炩�Ƀ��[���A�h���X����Ȃ����͏��O
			if(preg_match("/[\x80-\xA0]/",$from)||stristr($from,'sage')||stristr($from,'http://'))	$from = '';
			// ���[���A�h���X���Ȃ���Α�ւ�
			if(!$from)	$from = 'nomail@'.getenv("HTTP_HOST");
			// ���{��Ȃ�MIME�w�b�h
			if(preg_match("/[\x80-\xA0]/",$name)){
				$name = "=?iso-2022-jp?B?".base64_encode(JcodeConvert($name,0,3))."?=";
			}
			// �w�b�_��From�ǉ�
			$MailHeaders .= "From: ".$name." <".$from.">\n";
			// Subject�ɓ��{�ꂪ�����MIME�w�b�h
			if(preg_match("/[\x80-\xA0]/",$data[subject])){
				$data[subject] = "=?iso-2022-jp?B?".base64_encode(JcodeConvert($data[subject],0,3))."?=";
			}
			// ���[�����M
			mail($data[to],
				$data[subject],
				JcodeConvert($Message,0,3), $MailHeaders);

		}else{ return false; }
		return true;
	}
}
?>