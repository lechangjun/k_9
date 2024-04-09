using UnityEngine;

public class ClickableObject : MonoBehaviour
{
    private bool isClicked = false;

    private void OnMouseDown()
    {
        if (!isClicked)
        {
            // 마우스 클릭 시 선택 창을 띄우는 함수 호출
            ShowSelectionMenu();
        }
    }

    private void ShowSelectionMenu()
    {
        // 선택 창을 띄우는 코드
        Debug.Log("1. 회전\n2. 아동\n3. 삭제");

        // 사용자의 입력을 받아 선택한 작업을 수행하는 함수 호출
        HandleUserInput();
    }

    private void HandleUserInput()
    {
        // 사용자의 입력을 받아 해당 작업을 수행하는 코드
        string input = Input.inputString;

        switch (input)
        {
            case "1":
                RotateObject();
                break;
            case "2":
                // 아동 기능을 수행하는 코드 작성
                Debug.Log("아동 기능을 수행합니다.");
                break;
            case "3":
                DeleteObject();
                break;
            default:
                Debug.Log("올바른 선택을 입력하세요.");
                break;
        }
    }

    private void RotateObject()
    {
        // 게임 오브젝트를 회전시키는 코드
        // 예를 들어, 아래의 코드는 게임 오브젝트를 90도 회전시킵니다.
        transform.Rotate(Vector3.up, 90f);
    }

    private void DeleteObject()
    {
        // 게임 오브젝트를 삭제하는 코드
        Destroy(gameObject);
    }
}
